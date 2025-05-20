//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_PASSIVES 100

/* Define structure for passive components */
typedef struct {
    char type;
    double value;
    int node1;
    int node2;
} Passive;

int main() {
    /* Declare variables */
    int num_nodes, num_passives, num_tests, i, j, k, l, m, n;
    double time_step, stop_time, source_voltage, resistor_value;
    char source_type;
    
    /* Prompt for circuit information */
    printf("Enter the number of nodes in the circuit (excluding ground): ");
    scanf("%d", &num_nodes);
    printf("Enter the number of passive components in the circuit: ");
    scanf("%d", &num_passives);
    printf("Enter the time step: ");
    scanf("%lf", &time_step);
    printf("Enter the stop time: ");
    scanf("%lf", &stop_time);
    
    /* Declare arrays for nodal voltage and previous nodal voltage */
    double node_voltages[MAX_NODES];
    double prev_node_voltages[MAX_NODES];
    double source_voltages[MAX_NODES];
    
    /* Initialize arrays to 0 */
    for (i = 0; i < MAX_NODES; i++) {
        node_voltages[i] = 0.0;
        prev_node_voltages[i] = 0.0;
        source_voltages[i] = 0.0;
    }
    
    /* Declare array for passive components */
    Passive passives[MAX_PASSIVES];
    
    /* Prompt for passive component information */
    for (i = 0; i < num_passives; i++) {
        printf("Enter the type of passive component %d (R, C, or L): ", i+1);
        scanf(" %c", &passives[i].type);
        printf("Enter the value of passive component %d: ", i+1);
        scanf("%lf", &passives[i].value);
        printf("Enter the first node of passive component %d: ", i+1);
        scanf("%d", &passives[i].node1);
        printf("Enter the second node of passive component %d: ", i+1);
        scanf("%d", &passives[i].node2);
    }
    
    /* Declare array for initial values of source voltages */
    for (i = 1; i < num_nodes; i++) {
        printf("Enter the initial voltage for node %d: ", i);
        scanf("%lf", &node_voltages[i]);
        prev_node_voltages[i] = node_voltages[i];
    }
    
    /* Prompt for source information */
    printf("Enter the type of source (V for voltage or C for current): ");
    scanf(" %c", &source_type);
    printf("Enter the value of the source: ");
    scanf("%lf", &source_voltage);
    printf("Enter the resistance of the resistor connected to the source: ");
    scanf("%lf", &resistor_value);
    printf("Enter the number of tests: ");
    scanf("%d", &num_tests);
    
    /* Print out circuit information */
    printf("\nCircuit Information:\n");
    printf("Number of Nodes: %d\n", num_nodes);
    printf("Number of Passives: %d\n", num_passives);
    printf("Time Step: %lf\n", time_step);
    printf("Stop Time: %lf\n", stop_time);
    printf("Source Type: %c\n", source_type);
    printf("Source Voltage: %lf\n", source_voltage);
    printf("Resistor Value: %lf\n", resistor_value);
    printf("Number of Tests: %d\n\n", num_tests);
    
    /* Print out passive component information */
    printf("Passive Components:\n");
    for (i = 0; i < num_passives; i++) {
        printf("%c%d: %lf\n", passives[i].type, i+1, passives[i].value);
        printf("Nodes: %d, %d\n", passives[i].node1, passives[i].node2);
    }
    printf("\n");
    
    /* Print out initial node voltages */
    printf("Initial Node Voltages:\n");
    for (i = 1; i < num_nodes; i++) {
        printf("Node %d: %lf\n", i, node_voltages[i]);
    }
    printf("\n");
    
    /* Print out source information */
    printf("Source Information:\n");
    printf("Type: %c\n", source_type);
    printf("Voltage: %lf\n", source_voltage);
    printf("Resistor Value: %lf\n", resistor_value);
    printf("\n");
    
    /* Run circuit simulation */
    for (i = 0; i <= num_tests; i++) {
        double t = i*time_step;
        double source_current = (source_type == 'C') ? source_voltage/resistor_value : 0.0;
        double source_voltage_drop = source_current*resistor_value;
        double source_voltage_at_t = (t <= stop_time) ? source_voltage : 0.0;
        
        /* Calculate node voltages */
        for (j = 1; j < num_nodes; j++) {
            double g = 0.0;
            double c = 0.0;
            double b = 0.0;
            
            /* Calculate conductance matrix */
            for (k = 0; k < num_passives; k++) {
                double value = passives[k].value;
                
                if (passives[k].type == 'R') {
                    if (j == passives[k].node1 && passives[k].node2 != 0) {
                        g += 1.0/value;
                    } else if (j == passives[k].node2 && passives[k].node1 != 0) {
                        g += 1.0/value;
                    }
                } else if (passives[k].type == 'C') {
                    if (j == passives[k].node1 && passives[k].node2 != 0) {
                        c += value/time_step;
                    } else if (j == passives[k].node2 && passives[k].node1 != 0) {
                        c += value/time_step;
                    }
                } else if (passives[k].type == 'L') {
                    if (j == passives[k].node1 && passives[k].node2 != 0) {
                        g += time_step/value;
                    } else if (j == passives[k].node2 && passives[k].node1 != 0) {
                        g += time_step/value;
                    }
                }
            }
            
            /* Calculate source vector */
            if (j == 1) {
                b += source_voltage_at_t-source_voltage_drop;
            } else {
                b -= source_current;
            }
            
            /* Calculate previous result vector */
            double prev_result = 0.0;
            for (l = 0; l < num_passives; l++) {
                double value = passives[l].value;
                if (passives[l].type == 'C') {
                    if (j == passives[l].node1 && passives[l].node2 != 0) {
                        prev_result += prev_node_voltages[passives[l].node2]*value/time_step;
                    } else if (j == passives[l].node2 && passives[l].node1 != 0) {
                        prev_result += prev_node_voltages[passives[l].node1]*value/time_step;
                    }
                } else if (passives[l].type == 'L') {
                    if (j == passives[l].node1 && passives[l].node2 != 0) {
                        prev_result += prev_node_voltages[passives[l].node2]/(value*time_step);
                    } else if (j == passives[l].node2 && passives[l].node1 != 0) {
                        prev_result += prev_node_voltages[passives[l].node1]/(value*time_step);
                    }
                }
            }
            
            /* Summation for the solution */
            node_voltages[j] = (g+c/time_step)*node_voltages[j]+(-1.0*b+prev_result)/time_step;
        }
        
        /* Print out node voltages at current time */
        printf("Voltage at %lf:\n", t);
        for (m = 1; m < num_nodes; m++) {
            printf("Node %d: %lf\n", m, node_voltages[m]);
            prev_node_voltages[m] = node_voltages[m];
        }
        printf("\n");
    }
    
    return 0;
}