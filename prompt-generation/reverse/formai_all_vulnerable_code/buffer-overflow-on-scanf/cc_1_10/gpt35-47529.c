//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define maximum number of attempts allowed */
#define MAX_ATTEMPTS 5

/* Define maximum length of user input */
#define MAX_INPUT_LENGTH 50

/* Define keyword to trigger intrusion alert */
#define TRIGGER_KEYWORD "hack"

/* Define function to clear user input buffer */
void clear_input_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    /* Initialize variables */
    char input[MAX_INPUT_LENGTH];
    int attempts = 0;

    /* Loop until user exhausts maximum attempts allowed */
    while(attempts < MAX_ATTEMPTS){

        /* Prompt user for input */
        printf("Enter username: ");
        scanf("%s", input);

        /* Verify user input */
        if(strcmp(input, "admin") == 0){

            /* Prompt user for password */
            printf("Enter password: ");
            scanf("%s", input);

            /* Verify user input */
            if(strcmp(input, "password") == 0){

                /* Password accepted */
                printf("Welcome, admin!");

                /* Clear input buffer */
                clear_input_buffer();
                
                /* Monitor user input for intrusion attempt */
                while(1){
                    printf("\n\nEnter command: ");
                    scanf("%s", input);
                    if(strstr(input, TRIGGER_KEYWORD) != NULL){
                        printf("\n\nALERT: Intrusion attempt detected!");
                        exit(0);
                    }
                    else{
                        printf("\n\nCommand executed successfully.");
                        clear_input_buffer();
                    }
                }

            }
            else{
                /* Invalid password */
                printf("Invalid password. Access denied.\n");
                attempts++;
            }

        }
        else{
            /* Invalid username */
            printf("Invalid username. Access denied.\n");
            attempts++;
        }
    }

    /* Maximum attempts reached. Abort program */
    printf("Maximum login attempts reached. Abort.\n");
    return 0;
}