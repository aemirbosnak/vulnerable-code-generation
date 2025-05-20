//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(){
    int size = 1024;
    char* mem = (char*) malloc(size*sizeof(char));

    clock_t start_time = clock();
    double total_time = 0.0;
    double cpu_usage = 0.0;

    while(1){
        clock_t current_time = clock();
        double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;

        if(elapsed_time >= 1.0){
            total_time += elapsed_time;
            start_time = current_time;
            FILE* fp = fopen("/proc/stat", "r");

            if(fp == NULL){
                printf("Error opening file!\n");
                exit(EXIT_FAILURE);
            }

            char* line = NULL; 
            size_t len = 0;
            ssize_t read;

            while((read = getline(&line, &len, fp)) != -1){
                if(strncmp(line, "cpu ", 4) == 0){
                    char* token = strtok(line, " ");

                    int i = 0;
                    while(token != NULL){
                        if(i == 0){
                            token = strtok(NULL, " ");
                            i++;
                            continue;
                        }

                        cpu_usage += atoi(token);
                        token = strtok(NULL, " ");
                        i++;
                    }

                    break;
                }
            }

            cpu_usage /= total_time;

            printf("CPU usage: %lf%%\n", cpu_usage);

            fclose(fp);

            free(line);
        }

        memset(mem, 'a', size*sizeof(char));
        usleep(100);
    }

    free(mem);

    return 0;
}