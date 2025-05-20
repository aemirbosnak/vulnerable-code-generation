//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// function to display menu and return input option
int displayMenu() {
    int option;
    printf("\nElectronic Voting System Menu:\n");
    printf("1. Register Voter\n");
    printf("2. Display Registered Voters\n");
    printf("3. Cast Vote\n");
    printf("4. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    return option;
}

// function to register a new voter
void registerVoter(char* name, int* age, int* voterID) {
    printf("\nEnter voter details:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", age);
    printf("Voter ID: ");
    scanf("%d", voterID);
    printf("Voter registration successful!\n");
}

// function to display the list of registered voters
void displayVoters(char voterList[][20], int ageList[], int idList[], int numVoters) {
    printf("\nRegistered Voters:\n");
    for(int i=0; i<numVoters; i++) {
        printf("%d. %s (Age: %d, ID: %d)\n", i+1, voterList[i], ageList[i], idList[i]);
    }
}

// function to cast a vote
void castVote(char voterList[][20], int ageList[], int idList[], int numVoters, int votes[]) {
    int selected;
    printf("\nCasting Vote:\n");
    printf("Select your candidate:\n");
    for(int i=0; i<numVoters; i++) {
        printf("%d. %s\n", i+1, voterList[i]);
    }
    printf("Enter your choice: ");
    scanf("%d", &selected);
    if(selected < 1 || selected > numVoters) {
        printf("Invalid option!\n");
        return;
    }
    votes[selected-1]++;
    printf("Thank you for voting!\n");
}

int main() {
    char voterList[100][20];
    int ageList[100], idList[100], votes[100] = {0};
    int numVoters = 0;
    int option;
    char name[20];
    int age, voterID;

    while(1) {
        option = displayMenu();
        switch(option) {
            case 1:
                registerVoter(name, &age, &voterID);
                strcpy(voterList[numVoters], name);
                ageList[numVoters] = age;
                idList[numVoters] = voterID;
                numVoters++;
                break;
            case 2:
                displayVoters(voterList, ageList, idList, numVoters);
                break;
            case 3:
                castVote(voterList, ageList, idList, numVoters, votes);
                break;
            case 4:
                printf("\nExiting Electronic Voting System...\n");
                exit(0);
            default:
                printf("\nInvalid option!");
        }
    }

    return 0;
}