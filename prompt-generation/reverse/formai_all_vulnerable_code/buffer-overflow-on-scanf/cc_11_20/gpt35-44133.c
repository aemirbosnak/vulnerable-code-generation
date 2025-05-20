//FormAI DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    // Initialize variables and structures
    int num_of_cores, num_of_processors, num_of_services;
    int core_loads[100], service_priorities[100], service_cores[100];
    double processor_speeds[100];
    struct service {
        char name[20];
        int priority;
        int cores_required;
    } services[100];

    // Set the number of CPU cores
    printf("Enter the number of CPU cores: ");
    scanf("%d", &num_of_cores);

    // Set the number of processors
    printf("Enter the number of processors: ");
    scanf("%d", &num_of_processors);

    // Set the number of services to be optimized
    printf("Enter the number of services to be optimized: ");
    scanf("%d", &num_of_services);

    // Get the processor speeds
    for(int i=0; i<num_of_processors; i++){
        printf("Enter the speed of processor %d: ", (i+1));
        scanf("%lf", &processor_speeds[i]);
    }

    // Get the services details
    for(int i=0; i<num_of_services; i++){
        printf("Enter the name of service %d: ", (i+1));
        scanf("%s", services[i].name);
        printf("Enter the priority of service %d: ", (i+1));
        scanf("%d", &service_priorities[i]);
        printf("Enter the number of cores required for service %d: ", (i+1));
        scanf("%d", &service_cores[i]);
    }

    // Distribute the services across the cores
    srand(time(0));
    for(int i=0; i<num_of_services; i++){
        int selected_core = rand() % num_of_cores;
        core_loads[selected_core] += service_cores[i];
    }

    // Calculate the total time taken to complete the services on each processor
    double time_taken[num_of_processors];
    for(int i=0; i<num_of_processors; i++){
        time_taken[i] = 0;
        for(int j=0; j<num_of_cores; j++){
            if(processor_speeds[i] < core_loads[j]){
                time_taken[i] += core_loads[j] / processor_speeds[i];
            }
            else{
                time_taken[i] += 1.0;
            }
        }
    }

    // Assign the services to the processor based on priority and speed
    for(int i=0; i<num_of_services; i++){
        int selected_processor = -1;
        int selected_priority = 0;
        double lowest_time_taken = 9999999999;
        for(int j=0; j<num_of_processors; j++){
            if(processor_speeds[j] > 0){
                double time_if_added = time_taken[j] + ((double)service_cores[i] / processor_speeds[j]);
                if(service_priorities[i] >= selected_priority && time_if_added < lowest_time_taken){
                    selected_priority = service_priorities[i];
                    selected_processor = j;
                    lowest_time_taken = time_if_added;
                }
            }
        }
        // Update the processor details and core loads
        if(selected_processor != -1){
            printf("Service %s assigned to processor %d\n", services[i].name, (selected_processor+1));
            processor_speeds[selected_processor] -= (double)service_cores[i] / lowest_time_taken;
            time_taken[selected_processor] = lowest_time_taken;
            for(int j=0; j<num_of_cores; j++){
                if(core_loads[j] >= service_cores[i]){
                    service_cores[i] = 0;
                    core_loads[j] -= service_cores[i];
                    break;
                }
            }
        }
        else{
            printf("Warning: Service %s could not be assigned to any processor\n", services[i].name);
        }
    }
    return 0;
}