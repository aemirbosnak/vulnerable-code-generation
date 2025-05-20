//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers
int getRandom(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    int lights[10] = {0}; //Initialize all lights to off
    srand(time(0)); //Seed for random number generation

    printf("Welcome to Medieval Style Light Control System\n");

    while(1){
        printf("\nSelect an option:\n");
        printf("1. Turn on all lights\n");
        printf("2. Turn off all lights\n");
        printf("3. Turn on a random light\n");
        printf("4. Turn off a random light\n");
        printf("5. Show light status\n");
        printf("6. Exit\n");

        int option;
        scanf("%d", &option);

        switch(option){
            case 1:
                for(int i=0; i<10; i++){
                    lights[i] = 1;
                }
                printf("All lights turned on!\n");
                break;

            case 2:
                for(int i=0; i<10; i++){
                    lights[i] = 0;
                }
                printf("All lights turned off!\n");
                break;

            case 3:
                {
                    int light = getRandom(0, 9);
                    lights[light] = 1;
                    printf("Light %d turned on!\n", light+1);
                }
                break;

            case 4:
                {
                    int light = getRandom(0, 9);
                    lights[light] = 0;
                    printf("Light %d turned off!\n", light+1);
                }
                break;

            case 5:
                {
                    printf("Light status:\n");
                    for(int i=0; i<10; i++){
                        printf("Light %d: %s\n", i+1, lights[i] ? "ON" : "OFF");
                    }
                }
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option selected!\n");
                break;
        }
    }

    return 0;
}