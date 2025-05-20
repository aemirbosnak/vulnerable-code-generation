//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
#define MAX_NODES 50 //maximum number of nodes
#define MAX_ELEMENTS 50 //maximum number of elements
#define PI 3.14159265
 
typedef struct complex
{
    float real, imag;
} complex;
 
typedef struct element
{
    char name[10];
    int nodes[2];
    float value;
} element;
 
int read_netlist(element[], char[]);
void construct_G(element[], int, complex [][MAX_NODES + 1]);
void construct_B(element[], int, complex [][MAX_NODES + 1]);
void construct_C(element[], int, complex [][MAX_NODES + 1], float);
void construct_D(element[], int, complex [][MAX_NODES + 1], float);
void solve(complex [][MAX_NODES + 1], int);
void print_matrices(complex [][MAX_NODES + 1], int);
void print_solution(complex [], int);
complex compute_impedance(float, float);
complex cmplx(float, float);
 
int main(int argc, char *argv[])
{
    char filename[50];
    element netlist[MAX_ELEMENTS];
    int num_elements;
    complex Yn[MAX_NODES + 1][MAX_NODES + 2];
    float time_step = 0.0001;
 
    if (argc != 2)
    {
        printf("Please enter the file name containing the netlist.\n");
        exit(1);
    }
 
    sscanf(argv[1], "%s", filename);
    num_elements = read_netlist(netlist, filename);
 
    construct_G(netlist, num_elements, Yn);
    construct_B(netlist, num_elements, Yn);
    construct_C(netlist, num_elements, Yn, time_step);
    construct_D(netlist, num_elements, Yn, time_step);
 
    solve(Yn, num_elements);
 
    printf("\nMatrices:\n");
    print_matrices(Yn, num_elements);
    printf("\nSolutions:\n");
    print_solution(Yn[MAX_NODES + 1], num_elements);
 
    return 0;
}
 
// Function to read netlist from file
int read_netlist(element netlist[], char filename[])
{
    FILE *fp;
    char line[500], *tokens;
    int i = 0, node1, node2;
 
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open input file.\n");
        exit(1);
    }
 
    while (fgets(line, 500, fp) != NULL)
    {
        tokens = strtok(line, " \n\t");
        strcpy(netlist[i].name, tokens);
 
        tokens = strtok(NULL, " \n\t");
        sscanf(tokens, "%d", &node1);
        netlist[i].nodes[0] = node1;
 
        tokens = strtok(NULL, " \n\t");
        sscanf(tokens, "%d", &node2);
        netlist[i].nodes[1] = node2;
 
        tokens = strtok(NULL, " \n\t");
        sscanf(tokens, "%f", &netlist[i].value);
 
        i++;
    }
 
    fclose(fp);
    return i;
}
 
// Function to construct G matrix
void construct_G(element netlist[], int num_elements, complex Yn[][MAX_NODES + 1])
{
    int i, j;
 
    for (i = 1; i <= MAX_NODES; i++)
    {
        for (j = 1; j <= MAX_NODES; j++)
        {
            Yn[i][j] = cmplx(0, 0);
        }
    }
 
    for (i = 1; i <= num_elements; i++)
    {
        if (netlist[i].name[0] == 'R')
        {
            complex Z = compute_impedance(netlist[i].value, 0.0);
            Yn[netlist[i].nodes[0]][netlist[i].nodes[0]] = 
                cmplx(Yn[netlist[i].nodes[0]][netlist[i].nodes[0]].real + 1/Z.real, Yn[netlist[i].nodes[0]][netlist[i].nodes[0]].imag + 1/Z.imag);
            Yn[netlist[i].nodes[0]][netlist[i].nodes[1]] = 
                cmplx(Yn[netlist[i].nodes[0]][netlist[i].nodes[1]].real - 1/Z.real, Yn[netlist[i].nodes[0]][netlist[i].nodes[1]].imag - 1/Z.imag);
            Yn[netlist[i].nodes[1]][netlist[i].nodes[0]] = 
                cmplx(Yn[netlist[i].nodes[1]][netlist[i].nodes[0]].real - 1/Z.real, Yn[netlist[i].nodes[1]][netlist[i].nodes[0]].imag - 1/Z.imag);
            Yn[netlist[i].nodes[1]][netlist[i].nodes[1]] = 
                cmplx(Yn[netlist[i].nodes[1]][netlist[i].nodes[1]].real + 1/Z.real, Yn[netlist[i].nodes[1]][netlist[i].nodes[1]].imag + 1/Z.imag);
        }
    }
}
 
// Function to construct B matrix
void construct_B(element netlist[], int num_elements, complex Yn[][MAX_NODES + 1])
{
    int i, j;
 
    for (i = 1; i <= num_elements; i++)
    {
        if (netlist[i].name[0] == 'I')
        {
            Yn[netlist[i].nodes[0]][MAX_NODES + 1] = 
                cmplx(Yn[netlist[i].nodes[0]][MAX_NODES + 1].real - netlist[i].value, Yn[netlist[i].nodes[0]][MAX_NODES + 1].imag);
            Yn[netlist[i].nodes[1]][MAX_NODES + 1] = 
                cmplx(Yn[netlist[i].nodes[1]][MAX_NODES + 1].real + netlist[i].value, Yn[netlist[i].nodes[1]][MAX_NODES + 1].imag);
        }
    }
}
 
// Function to construct C matrix
void construct_C(element netlist[], int num_elements, complex Yn[][MAX_NODES + 1], float time_step)
{
    int i, j;
 
    for (i = 1; i <= num_elements; i++)
    {
        if (netlist[i].name[0] == 'C')
        {
            complex Z = compute_impedance(0.0, (float)(1.0 / (2.0 * PI * netlist[i].value * time_step)));
            Yn[netlist[i].nodes[0]][netlist[i].nodes[0]] = 
                cmplx(Yn[netlist[i].nodes[0]][netlist[i].nodes[0]].real + Z.real, Yn[netlist[i].nodes[0]][netlist[i].nodes[0]].imag + Z.imag);
            Yn[netlist[i].nodes[0]][netlist[i].nodes[1]] = 
                cmplx(Yn[netlist[i].nodes[0]][netlist[i].nodes[1]].real - Z.real, Yn[netlist[i].nodes[0]][netlist[i].nodes[1]].imag - Z.imag);
            Yn[netlist[i].nodes[1]][netlist[i].nodes[0]] = 
                cmplx(Yn[netlist[i].nodes[1]][netlist[i].nodes[0]].real - Z.real, Yn[netlist[i].nodes[1]][netlist[i].nodes[0]].imag - Z.imag);
            Yn[netlist[i].nodes[1]][netlist[i].nodes[1]] = 
                cmplx(Yn[netlist[i].nodes[1]][netlist[i].nodes[1]].real + Z.real, Yn[netlist[i].nodes[1]][netlist[i].nodes[1]].imag + Z.imag);
        }
    }
}
 
// Function to construct D matrix
void construct_D(element netlist[], int num_elements, complex Yn[][MAX_NODES + 1], float time_step)
{
    int i, j;
 
    for (i = 1; i <= num_elements; i++)
    {
        if (netlist[i].name[0] == 'D')
        {
            complex Z = compute_impedance(0.0, 1.0 / netlist[i].value * time_step);
            Yn[netlist[i].nodes[0]][netlist[i].nodes[0]] = 
                cmplx(Yn[netlist[i].nodes[0]][netlist[i].nodes[0]].real + Z.real, Yn[netlist[i].nodes[0]][netlist[i].nodes[0]].imag + Z.imag);
            Yn[netlist[i].nodes[0]][netlist[i].nodes[1]] = 
                cmplx(Yn[netlist[i].nodes[0]][netlist[i].nodes[1]].real - Z.real, Yn[netlist[i].nodes[0]][netlist[i].nodes[1]].imag - Z.imag);
            Yn[netlist[i].nodes[1]][netlist[i].nodes[0]] = 
                cmplx(Yn[netlist[i].nodes[1]][netlist[i].nodes[0]].real - Z.real, Yn[netlist[i].nodes[1]][netlist[i].nodes[0]].imag - Z.imag);
            Yn[netlist[i].nodes[1]][netlist[i].nodes[1]] = 
                cmplx(Yn[netlist[i].nodes[1]][netlist[i].nodes[1]].real + Z.real, Yn[netlist[i].nodes[1]][netlist[i].nodes[1]].imag + Z.imag);
        }
    }
}
 
// Function to solve the circuit
void solve(complex Yn[][MAX_NODES + 1], int num_elements)
{
    int i, j, k, p;
    complex temp, factor;
 
    for (i = 1; i <= MAX_NODES; i++)
    {
        for (j = i + 1; j <= MAX_NODES; j++)
        {
            if (Yn[i][i].real == 0)
            {
                printf("There is a zero in the diagonal element.\n");
                exit(1);
            }
 
            factor = cmplx(Yn[j][i].real / Yn[i][i].real, Yn[j][i].imag / Yn[i][i].real);
            for (k = i; k <= MAX_NODES + 1; k++)
            {
                Yn[j][k].real = Yn[j][k].real - factor.real * Yn[i][k].real + factor.imag * Yn[i][k].imag;
                Yn[j][k].imag = Yn[j][k].imag - factor.real * Yn[i][k].imag - factor.imag * Yn[i][k].real;
            }
        }
    }
 
    for (i = MAX_NODES; i >= 1; i--)
    {
        for (j = i - 1; j >= 1; j--)
        {
            if (Yn[i][i].real == 0)
            {
                printf("There is a zero in the diagonal element.\n");
                exit(1);
            }
 
            factor = cmplx(Yn[j][i].real / Yn[i][i].real, Yn[j][i].imag / Yn[i][i].real);
            for (k = MAX_NODES + 1; k >= i; k--)
            {
                Yn[j][k].real = Yn[j][k].real - factor.real * Yn[i][k].real + factor.imag * Yn[i][k].imag;
                Yn[j][k].imag = Yn[j][k].imag - factor.real * Yn[i][k].imag - factor.imag * Yn[i][k].real;
            }
        }
    }
 
    for (i = 1; i <= MAX_NODES; i++)
    {
        if (Yn[i][i].real == 0)
        {
            printf("There is a zero in the diagonal element.\n");
            exit(1);
        }
 
        temp = cmplx(Yn[i][MAX_NODES + 1].real / Yn[i][i].real, Yn[i][MAX_NODES + 1].imag / Yn[i][i].real);
        Yn[i][MAX_NODES + 1] = temp;
    }
}
 
// Function to print matrices
void print_matrices(complex Yn[][MAX_NODES + 1], int num_elements)
{
    int i, j;
 
    for (i = 1; i <= MAX_NODES; i++)
    {
        for (j = 1; j <= MAX_NODES; j++)
        {
            printf("%f + %fi ", Yn[i][j].real, Yn[i][j].imag);
        }
        printf("\n");
    }
}
 
// Function to print solution vector
void print_solution(complex sol[], int num_elements)
{
    int i;
 
    for (i = 1; i <= MAX_NODES; i++)
    {
        printf("V%d: %f + %fi\n", i, sol[i].real, sol[i].imag);
    }
}
 
// Function to calculate the impedance of an element
complex compute_impedance(float resistance, float reactance)
{
    return cmplx(resistance, reactance);
}
 
// Function to create a complex number with the given real and imaginary parts
complex cmplx(float real, float imag)
{
    complex c;
    c.real = real;
    c.imag = imag;
    return c;
}