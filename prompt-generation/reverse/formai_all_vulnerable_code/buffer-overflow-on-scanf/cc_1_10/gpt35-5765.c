//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
/* Welcome to the world of circuit simulation! */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/* Define the structure for each element in the circuit */
typedef struct element{
    int node1;
    int node2;
    double value;
    char type;
}element;

/* Define the structure for the circuit */
typedef struct circuit{
    element elements[MAX];
    int num_elements;
}circuit;

/* Function to add new element to the circuit */
void add_element(circuit *cir){
    printf("Enter the type of element (R, L, C, V, I): ");
    scanf(" %c", &cir->elements[cir->num_elements].type);
    printf("Enter the nodes this element is connected to: ");
    scanf("%d %d", &cir->elements[cir->num_elements].node1, &cir->elements[cir->num_elements].node2);
    printf("Enter the value of this element: ");
    scanf("%lf", &cir->elements[cir->num_elements].value);
    cir->num_elements++;
}

/* Function to print the circuit */
void print_circuit(circuit *cir){
    printf("\n---Printing Circuit---\n");
    for(int i=0; i<cir->num_elements; i++){
        printf("%c: Nodes(%d,%d) Value:%.2lf\n", cir->elements[i].type, cir->elements[i].node1, cir->elements[i].node2, cir->elements[i].value);
    }
}

int main(){
    
    /* Initialize the circuit */
    circuit cir;
    cir.num_elements = 0;
    
    /* Welcome message */
    printf("Welcome to the Classical Circuit Simulator!\n");
    
    /* Main loop */
    char choice;
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("A - Add element to the circuit\n");
        printf("P - Print the circuit\n");
        printf("E - Exit the simulator\n");
        printf("Your choice: ");
        scanf(" %c", &choice);
        switch(choice){
            case 'A':
                add_element(&cir);
                break;
            case 'P':
                print_circuit(&cir);
                break;
            case 'E':
                printf("Exiting the simulator...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}