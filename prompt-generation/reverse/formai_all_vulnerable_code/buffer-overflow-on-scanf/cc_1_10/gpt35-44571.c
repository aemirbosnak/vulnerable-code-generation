//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This data recovery tool will not only recover lost data but also create a parallel universe where the lost data exist.

int main(){
    char file_name[50];
    char universe_name[50];
    char recovery_option;
    char overwrite_option;

    printf("---------------------------\n");
    printf("Welcome to Data Recovery Tool\n");
    printf("---------------------------\n");

    printf("Enter the name of the file you want to recover: ");
    scanf("%s", file_name);

    printf("Enter the name of the parallel universe you want to create: ");
    scanf("%s", universe_name);

    printf("Do you want to recover the data in the original file or create a parallel universe? (O/P)");
    recovery_option = getchar();
    recovery_option = toupper(recovery_option);
    while(recovery_option != 'O' && recovery_option != 'P'){
        printf("Invalid option, please select O or P: ");
        recovery_option = getchar();
        recovery_option = toupper(recovery_option);
    }

    FILE *original_file;
    FILE *parallel_universe;

    original_file = fopen(file_name, "r");
    if(original_file == NULL){
        printf("Sorry, unable to open the file.\n");
    }
    else{
        printf("File opened successfully.\n");

        parallel_universe = fopen(universe_name, "w");

        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int line_num = 1;

        printf("Data found in the original file:\n");

        while((read = getline(&line, &len, original_file)) != -1){
            printf("%d: %s", line_num, line);
            fprintf(parallel_universe, "%d: %s", line_num, line);
            line_num++;
        }

        fclose(original_file);
        fclose(parallel_universe);

        if(recovery_option == 'O'){
            printf("Do you want to overwrite the original file with the recovered data? (Y/N)");
            overwrite_option = getchar();
            overwrite_option = toupper(overwrite_option);
            while(overwrite_option != 'Y' && overwrite_option != 'N'){
                printf("Invalid option, please select Y or N: ");
                overwrite_option = getchar();
                overwrite_option = toupper(overwrite_option);
            }

            if(overwrite_option == 'Y'){
                printf("Original file overwritten with the recovered data.\n");
                remove(file_name);
                rename(universe_name, file_name);
            }
            else{
                printf("Recovered data saved in parallel universe %s.\n", universe_name);
            }
        }
        else{
            printf("Parallel universe %s created with the recovered data.\n", universe_name);
        }
    }

    return 0;
}