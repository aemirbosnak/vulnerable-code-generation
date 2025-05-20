//FormAI DATASET v1.0 Category: System event logger ; Style: romantic
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    char name[20];
    printf("Welcome to our romantic system event logger!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("\n");
    printf("Hello, %s!\n", name);
    printf("We are going to log some important events in our romantic journey.\n");
    printf("Are you ready to begin?\n");
    
    char response[3];
    printf("Enter Y for yes and N for no: ");
    scanf("%s", response);
    
    while (response[0] != 'Y' && response[0] != 'N') {
        printf("Invalid response. Enter Y for yes and N for no: ");
        scanf("%s", response);
    }
    
    if (response[0] == 'N') {
        printf("You're breaking my heart. Goodbye!\n");
        return 0;
    }
    
    printf("\n");
    printf("Great! Let's get started.\n\n");
    
    int event_count = 0;
    char event[100];
    char date[20];
    
    while (event_count < 3) {
        printf("Enter an event that you want to remember (max 100 characters): ");
        scanf("%s", event);
        printf("Enter the date when it happened (dd/mm/yyyy): ");
        scanf("%s", date);
        
        FILE *fp = fopen("event_log.txt", "a");
        if (fp == NULL) {
            printf("Error: Cannot open file.\n");
            return 1;
        }
        
        fprintf(fp, "%s - %s: %s\n", date, name, event);
        fclose(fp);
        
        printf("Event logged!\n");
        printf("\n");
        
        event_count++;
    }
    
    printf("That's all for now. Here are the events that you have logged:\n\n");
    
    FILE *fp = fopen("event_log.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
    
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    
    fclose(fp);
    
    printf("\nThank you for using our romantic system event logger!");
    
    return 0;
}