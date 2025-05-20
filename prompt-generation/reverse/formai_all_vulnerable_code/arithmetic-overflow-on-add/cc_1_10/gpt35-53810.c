//FormAI DATASET v1.0 Category: System boot optimizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int boot_time, services, startup_scripts, i, j, total_time = 0; // variables to store boot time and service details
    printf("Welcome to the C System Boot Optimizer Program.\n\n");
    
    printf("Enter the current boot time of your system in seconds: ");
    scanf("%d", &boot_time); // get the current boot time from user
    
    printf("\nEnter the number of services running at startup: ");
    scanf("%d", &services); // get the number of services from user
    
    char service_names[services][20]; // array to store service names
    
    printf("\nEnter the names of services running at startup:\n");
    for(i = 0; i < services; i++) {
        printf("%d. ", i+1);
        scanf("%s", service_names[i]); // get the name of each service
    }
    
    printf("\nEnter the number of startup scripts running at startup: ");
    scanf("%d", &startup_scripts); // get the number of startup scripts from user
    
    char script_names[startup_scripts][20]; // array to store script names
    
    printf("\nEnter the names of startup scripts running at startup:\n");
    for(i = 0; i < startup_scripts; i++) {
        printf("%d. ", i+1);
        scanf("%s", script_names[i]); // get the name of each script
    }
    
    int script_times[startup_scripts]; // array to store execution times of scripts
    
    printf("\nEnter the execution time (in seconds) for each startup script:\n");
    for(i = 0; i < startup_scripts; i++) {
        printf("%s: ", script_names[i]);
        scanf("%d", &script_times[i]); // get the execution time of each script
    }
    
    // calculate the total boot time including service and startup script times
    for(i = 0; i < startup_scripts; i++) {
        total_time += script_times[i];
    }
    
    total_time += (services * 10); // assume each service takes 10 seconds to start
    
    printf("\nTotal boot time before optimization: %d seconds\n", boot_time + total_time);
    
    // sort startup scripts based on execution times using bubble sort
    for(i = 0; i < startup_scripts - 1; i++) {
        for(j = 0; j < startup_scripts - i - 1; j++) {
            if(script_times[j] < script_times[j+1]) {
                int temp = script_times[j];
                script_times[j] = script_times[j+1];
                script_times[j+1] = temp;
                
                char temp_name[20];
                strcpy(temp_name, script_names[j]);
                strcpy(script_names[j], script_names[j+1]);
                strcpy(script_names[j+1], temp_name);
            }
        }
    }
    
    // print the optimized order of startup scripts
    printf("\nOptimized order of startup scripts based on execution time:\n");
    for(i = 0; i < startup_scripts; i++) {
        printf("%d. %s\n", i+1, script_names[i]);
    }
    
    // calculate the boot time after optimization
    total_time = 0;
    for(i = 0; i < startup_scripts; i++) {
        total_time += script_times[i];
    }
    
    total_time += (services * 10);
    
    printf("\nTotal boot time after optimization: %d seconds\n", boot_time + total_time);
    
    printf("\nThank you for using the C System Boot Optimizer Program.\n");
    return 0;
}