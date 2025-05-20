//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 10//Maximum number of nodes in the circuit

//Functions to simulate various circuit elements
double Resistor(double res,double v_in,double v_out){
    return (v_in - v_out)/res;
}

double Capacitor(double cap,double v_in,double v_out,double dt){
    return cap*(v_in - v_out)/dt;
}

double Inductor(double ind,double i_in,double i_out,double dt){
    return (i_in - i_out)*dt/ind;
}

double VoltageSource(double volt,double t){
    return volt;
}

double getCurrent(double in_curr,double out_curr){
    return (in_curr - out_curr);
}

int main(){

    int num_nodes, num_elements, node1, node2, i,j,k;
    double value, time_step, sim_time;
    char element_type;

    double conductance_matrix[SIZE][SIZE], voltage_matrix[SIZE]={0}, current_matrix[SIZE]={0};
    double current_value, voltage_value;

    printf("Enter number of nodes: ");
    scanf("%d",&num_nodes);

    printf("Enter number of circuit elements: ");
    scanf("%d",&num_elements);

    printf("Enter simulation time (in seconds): ");
    scanf("%lf",&sim_time);

    printf("Enter time step (in seconds): ");
    scanf("%lf",&time_step);

    //Initialize the conductance matrix to zero
    for(i=0;i<num_nodes;i++){
        for(j=0;j<num_nodes;j++){
            conductance_matrix[i][j] = 0;
        }
    }

    //Get values of all the circuit elements
    for(k=0;k<num_elements;k++){
        printf("Enter element type (R for Resistor, C for Capacitor, L for Inductor, V for Voltage Source): ");
        scanf(" %c",&element_type);

        printf("Enter value of element: ");
        scanf("%lf",&value);

        printf("Enter value of first node: ");
        scanf("%d",&node1);

        printf("Enter value of second node: ");
        scanf("%d",&node2);

        if(element_type=='R'){
            conductance_matrix[node1-1][node1-1] += 1/value;
            conductance_matrix[node2-1][node2-1] += 1/value;
            conductance_matrix[node1-1][node2-1] -= 1/value;
            conductance_matrix[node2-1][node1-1] -= 1/value;
        }

        else if(element_type=='C'){
            conductance_matrix[node1-1][node1-1] += 2*value/time_step;
            conductance_matrix[node2-1][node2-1] += 2*value/time_step;
            conductance_matrix[node1-1][node2-1] -= 2*value/time_step;
            conductance_matrix[node2-1][node1-1] -= 2*value/time_step;
        }

        else if(element_type=='L'){
            conductance_matrix[node1-1][node1-1] += time_step/value;
            conductance_matrix[node2-1][node2-1] += time_step/value;
            conductance_matrix[node1-1][node2-1] -= time_step/value;
            conductance_matrix[node2-1][node1-1] -= time_step/value;
        }

        else if(element_type=='V'){
            current_matrix[node1-1] += value;
            current_matrix[node2-1] -= value;
        }
    }

    double total_time_steps = sim_time/time_step;

    FILE *fp;
    fp = fopen("circuit_simulation_results.txt", "w");

    fprintf(fp, "Time(s)\t");

    for(i=0;i<num_nodes;i++){
        fprintf(fp, "Voltage at Node %d(V)\t",i+1);
    }

    for(i=0;i<num_nodes;i++){
        fprintf(fp, "Current through Node %d(A)\t",i+1);
    }

    fprintf(fp, "\n");

    double t;

    //Perform simulation
    for(k=0;k<total_time_steps;k++){
        t = k*time_step;

        for(i=0;i<num_nodes;i++){
            for(j=0;j<num_nodes;j++){
                voltage_matrix[i] += conductance_matrix[i][j]*voltage_matrix[j];
            }
        }

        for(i=0;i<num_nodes;i++){
            current_value = 0;

            for(j=0;j<num_nodes;j++){
                current_value += conductance_matrix[i][j]*current_matrix[j];
            }

            voltage_value = voltage_matrix[i];

            if(i==0){
                current_matrix[i] += VoltageSource(current_matrix[i],t);
            }

            else{
                current_matrix[i] += getCurrent(current_matrix[i], current_matrix[j]);
            }

            current_matrix[i] += getCurrent(current_matrix[i], getCurrent(current_value,voltage_value));
        }

        fprintf(fp, "%lf\t",t);

        for(i=0;i<num_nodes;i++){
            fprintf(fp, "%lf\t",voltage_matrix[i]);
        }

        for(i=0;i<num_nodes;i++){
            fprintf(fp, "%lf\t",current_matrix[i]);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Simulation results have been written to file circuit_simulation_results.txt\n");

    return 0;
}