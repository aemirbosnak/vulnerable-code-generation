//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define constants
#define MAX_NODES 1000
#define MAX_VOLTAGE 10
#define MAX_CURRENT 10
#define MAX_RESISTANCE 10
#define MAX_TIME 10
#define PI 3.14159265359

//define variables
double node_voltage[MAX_NODES];
double node_current[MAX_NODES];
double resistance[MAX_NODES][MAX_NODES];
double capacitance[MAX_NODES][MAX_NODES];
double inductance[MAX_NODES][MAX_NODES];
double initial_voltage[MAX_NODES];
double final_voltage[MAX_NODES];
double time_step;
double end_time;
int num_nodes;
int num_resistors;
int num_capacitors;
int num_inductors;

//user-defined functions
void solve_circuit()
{
    int i, j, k;
    double temp_current;
    double temp_voltage;
    double delta_time = time_step;

    //solve for node voltages at time = 0
    for (i = 0; i < num_nodes; i++)
    {
        node_voltage[i] = initial_voltage[i];
    }

    //simulate circuit over time
    for (k = 0; k < (end_time / time_step); k++)
    {
        for (i = 0; i < num_nodes; i++)
        {
            temp_current = 0;
            temp_voltage = 0;

            //calculate current flowing into node
            for (j = 0; j < num_nodes; j++)
            {
                if (resistance[i][j] != 0)
                {
                    temp_current += (node_voltage[i] - node_voltage[j]) / resistance[i][j];
                }

                if (capacitance[i][j] != 0)
                {
                    temp_current += capacitance[i][j] * (node_voltage[i] - node_voltage[j]) / delta_time;
                }

                if (inductance[i][j] != 0)
                {
                    temp_current += inductance[i][j] * (node_voltage[i] - node_voltage[j]) * (2 * PI * delta_time);
                }
            }

            //store current flowing into node
            node_current[i] = temp_current;

            //calculate voltage at node
            for (j = 0; j < num_nodes; j++)
            {
                if (resistance[i][j] != 0)
                {
                    temp_voltage += (node_voltage[i] - node_voltage[j]) * resistance[i][j];
                }

                if (capacitance[i][j] != 0)
                {
                    temp_voltage += capacitance[i][j] * (node_voltage[i] - node_voltage[j]) / delta_time;
                }

                if (inductance[i][j] != 0)
                {
                    temp_voltage += inductance[i][j] * (node_voltage[i] - node_voltage[j]) / (2 * PI * delta_time);
                }
            }

            //add voltage source to node
            if (i == 0)
            {
                temp_voltage += MAX_VOLTAGE;
            }

            //store voltage at node
            node_voltage[i] = temp_voltage;
        }
    }

    //store final node voltages
    for (i = 0; i < num_nodes; i++)
    {
        final_voltage[i] = node_voltage[i];
    }
}

//main function
int main()
{
    int i, j;

    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of resistors in the circuit: ");
    scanf("%d", &num_resistors);

    printf("Enter the number of capacitors in the circuit: ");
    scanf("%d", &num_capacitors);

    printf("Enter the number of inductors in the circuit: ");
    scanf("%d", &num_inductors);

    printf("Enter the time step: ");
    scanf("%lf", &time_step);

    printf("Enter the end time: ");
    scanf("%lf", &end_time);

    //initialize circuit parameters
    for (i = 0; i < num_nodes; i++)
    {
        for (j = 0; j < num_nodes; j++)
        {
            resistance[i][j] = 0;
            capacitance[i][j] = 0;
            inductance[i][j] = 0;
        }
    }

    //initialize node voltages
    for (i = 0; i < num_nodes; i++)
    {
        node_voltage[i] = 0;
        node_current[i] = 0;
        initial_voltage[i] = 0;
        final_voltage[i] = 0;
    }

    //connect resistors in circuit
    for (i = 0; i < num_resistors; i++)
    {
        int r1, r2;
        double r_val;

        printf("Enter the first node of resistor %d: ", i + 1);
        scanf("%d", &r1);

        printf("Enter the second node of resistor %d: ", i + 1);
        scanf("%d", &r2);

        printf("Enter the resistance value: ");
        scanf("%lf", &r_val);

        resistance[r1][r2] = r_val;
        resistance[r2][r1] = r_val;
    }

    //connect capacitors in circuit
    for (i = 0; i < num_capacitors; i++)
    {
        int c1, c2;
        double c_val;

        printf("Enter the first node of capacitor %d: ", i + 1);
        scanf("%d", &c1);

        printf("Enter the second node of capacitor %d: ", i + 1);
        scanf("%d", &c2);

        printf("Enter the capacitance value: ");
        scanf("%lf", &c_val);

        capacitance[c1][c2] = c_val;
        capacitance[c2][c1] = c_val;
    }

    //connect inductors in circuit
    for (i = 0; i < num_inductors; i++)
    {
        int l1, l2;
        double l_val;

        printf("Enter the first node of inductor %d: ", i + 1);
        scanf("%d", &l1);

        printf("Enter the second node of inductor %d: ", i + 1);
        scanf("%d", &l2);

        printf("Enter the inductance value: ");
        scanf("%lf", &l_val);

        inductance[l1][l2] = l_val;
        inductance[l2][l1] = l_val;
    }

    //simulate circuit
    solve_circuit();

    //print results
    printf("Node voltages at time %.2lf:\n", end_time);
    for (i = 0; i < num_nodes; i++)
    {
        printf("Node %d: %.3lf V\n", i, final_voltage[i]);
    }

    return 0;
}