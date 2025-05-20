//FormAI DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <time.h>

int main(){
    FILE *logFile;
    time_t t;
    char logText[100];
    int choice;

    printf("\nWelcome to the Visionary Event Logger Program!\n");

    printf("\nPlease select from the following options:\n");
    printf("\n1. Record an event.\n");
    printf("\n2. Display all events.\n");
    printf("\n3. Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            logFile = fopen("eventLog.txt", "a");
            printf("\nEnter event description: ");
            scanf(" %[^\n]", logText);
            time(&t);
            fprintf(logFile, "%s - %s\n", asctime(localtime(&t)), logText);
            fclose(logFile);
            printf("\nEvent successfully recorded!\n");
            break;
        
        case 2:
            logFile = fopen("eventLog.txt", "r");
            if(logFile == NULL){
                printf("\nNo events recorded yet.\n");
            }
            else{
                printf("\n");
                char buffer[100];
                while(fgets(buffer, 100, logFile) != NULL){
                    printf("%s", buffer);
                }
                printf("\n");
                fclose(logFile);
            }
            break;
        
        case 3:
            printf("\nExiting the program...\n");
            break;
        
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
    return 0;
}