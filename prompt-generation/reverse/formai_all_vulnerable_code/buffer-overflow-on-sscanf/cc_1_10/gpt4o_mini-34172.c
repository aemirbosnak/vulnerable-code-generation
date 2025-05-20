//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SERVANTS 10
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char name[50];
    int taskStatus; // 0 - idle, 1 - working, 2 - completed
} Servant;

Servant servants[MAX_SERVANTS];
int servantCount = 0;

void registerServant(char *name) {
    if (servantCount < MAX_SERVANTS) {
        strcpy(servants[servantCount].name, name);
        servants[servantCount].taskStatus = 0; // idle
        servantCount++;
        printf("Hark! The servant %s hath been registered.\n", name);
    } else {
        printf("Alas! The servant roster is full!\n");
    }
}

void displayServants() {
    printf("List of Servants in the Kingdom:\n");
    for (int i = 0; i < servantCount; i++) {
        printf("%s - Status: %s\n", servants[i].name, 
            servants[i].taskStatus == 0 ? "Idle" 
            : (servants[i].taskStatus == 1 ? "Working" : "Completed"));
    }
}

void commandServant(char *name, char *task) {
    for (int i = 0; i < servantCount; i++) {
        if (strcmp(servants[i].name, name) == 0) {
            servants[i].taskStatus = 1; // working
            printf("Servant %s, thou art commanded to %s!\n", name, task);
            printf("Processing...");
            // Simulating task completion
            sleep(3);
            servants[i].taskStatus = 2; // completed
            printf("\nThy task is complete, %s!\n", name);
            return;
        }
    }
    printf("Alas! There is no servant by the name %s.\n", name);
}

void grantBlessing() {
    printf("A great blessing from the kingdom!\n");
    printf("May thy devices grant thee peace and prosperity!\n");
}

void executeCommand(char *command) {
    char servantName[50];
    char task[50];

    if (sscanf(command, "register %s", servantName) == 1) {
        registerServant(servantName);
    } else if (strcmp(command, "list") == 0) {
        displayServants();
    } else if (sscanf(command, "command %s %[^\n]", servantName, task) == 2) {
        commandServant(servantName, task);
    } else if (strcmp(command, "bless") == 0) {
        grantBlessing();
    } else {
        printf("Pray, speak plainly, for I understand not thy command.\n");
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    printf("Welcome to the Medieval Smart Home Automation System!\n");
    
    while (1) {
        printf("Enter thy command (or type 'exit' to leave): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Farewell, noble soul! The kingdom shall await thy return.\n");
            break;
        }
        executeCommand(command);
    }
    
    return 0;
}