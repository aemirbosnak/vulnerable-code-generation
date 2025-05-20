//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

//This program simulates a memory management system for statistical purposes

int main(){
    //Initialize variables
    int size, option, i, j, k, count;
    int *memory = NULL;
    int *procSize = NULL;

    //Welcome message
    printf("Welcome to Memory Management Simulation!\n");
    printf("----------------------------------------\n");

    //Prompt user for number of memory blocks
    printf("How many memory blocks do you want to create? ");
    scanf("%d", &size);

    //Dynamically allocate memory
    memory = (int*) malloc(size * sizeof(int));

    //Prompt user for initial values
    printf("Enter initial values for memory blocks:\n");
    for(i=0; i<size; i++){
        printf("Block %d: ", i+1);
        scanf("%d", &memory[i]);
    }

    //Display initial memory map
    printf("\nInitial Memory Map:\n");
    for(i=0; i<size; i++){
        printf("%d ", memory[i]);
    }

    //Loop for options
    do{
        printf("\n\nOptions:\n");
        printf("1. Allocate memory\n");
        printf("2. Deallocate memory\n");
        printf("3. View memory map\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                //Prompt user for process size
                printf("Enter process size: ");
                scanf("%d", &count);

                //Check if memory is available
                j = 0;
                k = 0;
                while(j < size && k < count){
                    if(memory[j] == 0){
                        k++;
                    }
                    j++;
                }

                //Allocate memory if available, else display message
                if(k == count){
                    procSize = (int*) malloc(count * sizeof(int));
                    printf("Enter values for process:\n");
                    for(i=0; i<count; i++){
                        printf("Value %d: ", i+1);
                        scanf("%d", &procSize[i]);
                    }

                    //Allocate memory blocks for process
                    j = 0;
                    k = 0;
                    while(j < size && k < count){
                        if(memory[j] == 0){
                            memory[j] = procSize[k];
                            k++;
                        }
                        j++;
                    }

                    printf("Memory allocated.");
                }
                else{
                    printf("Memory not available for process size %d.", count);
                }
                break;

            case 2:
                //Prompt user for process size
                printf("Enter process size: ");
                scanf("%d", &count);

                //Check if process is in memory
                j = 0;
                k = 0;
                while(j < size && k < count){
                    if(memory[j] != 0){
                        k++;
                    }
                    j++;
                }

                //Deallocate memory if process is in memory, else display message
                if(k == count){
                    j = 0;
                    k = 0;
                    while(j < size && k < count){
                        if(memory[j] != 0){
                            memory[j] = 0;
                            k++;
                        }
                        j++;
                    }

                    printf("Memory deallocated.");
                }
                else{
                    printf("Process not found in memory.");
                }
                break;

            case 3:
                //Display memory map
                printf("\nMemory Map:\n");
                for(i=0; i<size; i++){
                    printf("%d ", memory[i]);
                }
                break;

            case 4:
                //Exit program
                printf("\nThank you for using Memory Management Simulation!");
                break;

            default:
                //Invalid option
                printf("\nInvalid option.");
        }

    }while(option != 4);

    //Free dynamically allocated memory
    free(memory);

    return 0;
}