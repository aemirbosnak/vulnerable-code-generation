//FormAI DATASET v1.0 Category: System boot optimizer ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define MAX_BOOT_TIME 120
#define MAX_PROGRAMS 10

/* Program struct to store name and boot time */
typedef struct {
    char name[20];
    int boot_time;
} Program;

/* Compare function for qsort */
int compare_program(const void* a, const void* b){
    return ((Program*)a)->boot_time - ((Program*)b)->boot_time;
}

int main(){
    Program programs[MAX_PROGRAMS];
    int num_programs = 0;
    int total_boot_time = 0;
    bool optimization_needed = false;

    // Read in programs and their boot times
    printf("Enter program names and boot times:\n");
    for(int i=0; i<MAX_PROGRAMS; i++){
        printf("Program %d: ", i+1);
        scanf("%s %d", programs[i].name, &programs[i].boot_time);
        num_programs++;

        total_boot_time += programs[i].boot_time;
        if(total_boot_time > MAX_BOOT_TIME){
            printf("Warning: Boot time exceeds maximum. Last program will be ignored.\n");
            num_programs--;
            optimization_needed = true;
            break;
        }
    }

    // Sort programs by boot time
    qsort(programs, num_programs, sizeof(Program), compare_program);

    // Display programs and their boot times after sorting
    printf("\nPrograms sorted by boot time:\n");
    for(int i=0; i<num_programs; i++){
        printf("%s: %d seconds\n", programs[i].name, programs[i].boot_time);
    }

    // Check if any programs can be removed to optimize boot time
    if(total_boot_time > MAX_BOOT_TIME){
        int i = num_programs - 1;
        while(total_boot_time > MAX_BOOT_TIME){
            printf("\nRemoving %s to optimize boot time...\n", programs[i].name);

            total_boot_time -= programs[i].boot_time;
            i--;
            num_programs--;

            optimization_needed = true;
        }
    }

    // Display final programs and their boot times
    printf("\nFinal programs and their boot times:\n");
    for(int i=0; i<num_programs; i++){
        printf("%s: %d seconds\n", programs[i].name, programs[i].boot_time);
    }

    if(optimization_needed){
        printf("\nBoot time has been optimized to meet maximum limit of %d seconds.\n", MAX_BOOT_TIME);
    } else {
        printf("\nBoot time is within the maximum limit of %d seconds.\n", MAX_BOOT_TIME);
    }

    return 0;
}