//FormAI DATASET v1.0 Category: System boot optimizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, opt, i, j, k;
    printf("Welcome to C System boot optimizer program.\n");
    printf("Please enter the number of programs:\n");
    scanf("%d", &num);
    char **programs = (char**)malloc(num * sizeof(char*));
    int *times = (int*)malloc(num * sizeof(int));

    for(i = 0; i < num; i++) {
        programs[i] = (char*)malloc(20 * sizeof(char));
        printf("Enter program %d name: ", i+1);
        scanf("%s", programs[i]);
        printf("Enter program %d boot time: ", i+1);
        scanf("%d", &times[i]);
    }
   
    printf("\nChoose an optimization algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    scanf("%d", &opt);

    switch(opt) {
        case 1:
            // Bubble Sort
            for(i = 0; i < num-1; i++) {
                for(j = 0; j < num-i-1; j++) {
                    if(times[j] > times[j+1]) {
                        int temp_time = times[j];
                        times[j] = times[j+1];
                        times[j+1] = temp_time;

                        char temp_name[20];
                        strcpy(temp_name, programs[j]);
                        strcpy(programs[j], programs[j+1]);
                        strcpy(programs[j+1], temp_name);
                    }
                }
            }
            break;

        case 2:
            // Selection Sort
            for(i = 0; i < num-1; i++) {
                int min_index = i;
                for(j = i+1; j < num; j++) {
                    if(times[j] < times[min_index]) {
                        min_index = j;
                    }
                }
                int temp_time = times[i];
                times[i] = times[min_index];
                times[min_index] = temp_time;

                char temp_name[20];
                strcpy(temp_name, programs[i]);
                strcpy(programs[i], programs[min_index]);
                strcpy(programs[min_index], temp_name);
            }
            break;

        case 3:
            // Insertion Sort
            for(i = 1; i < num; i++) {
                int curr_time = times[i];
                char curr_name[20];
                strcpy(curr_name, programs[i]);
                j = i-1;
                while(j >= 0 && times[j] > curr_time) {
                    times[j+1] = times[j];
                    strcpy(programs[j+1], programs[j]);
                    j--;
                }
                times[j+1] = curr_time;
                strcpy(programs[j+1], curr_name);
            }
            break;

        default:
            printf("Invalid option selected.\n");
            exit(0);
    }

    printf("\nOptimization Complete. New Boot Order:\n");

    for(i = 0; i < num; i++) {
        printf("%d. %s\n", i+1, programs[i]);
    }

    return 0;
}