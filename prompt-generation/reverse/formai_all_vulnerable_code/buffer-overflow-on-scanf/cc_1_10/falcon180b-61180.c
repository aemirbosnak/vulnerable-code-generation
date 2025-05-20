//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void print_menu() {
    printf("1. Vote\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    candidate candidates[10];
    int num_candidates = 0;
    int i;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20];
    strftime(date, 20, "%d/%m/%Y", t);
    printf("Welcome to the Electronic Voting System!\n");
    printf("Today's date is %s.\n", date);
    printf("Please enter the number of candidates:\n");
    scanf("%d", &num_candidates);
    printf("Enter the name and ID of each candidate:\n");
    for (i = 0; i < num_candidates; i++) {
        scanf("%s %d", candidates[i].name, &candidates[i].votes);
    }
    printf("Voting has started!\n");
    do {
        system("clear");
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your ID:\n");
                int id;
                scanf("%d", &id);
                printf("Enter the ID of the candidate you want to vote for:\n");
                int candidate_id;
                scanf("%d", &candidate_id);
                for (i = 0; i < num_candidates; i++) {
                    if (candidates[i].votes == candidate_id) {
                        candidates[i].votes++;
                        printf("You have voted for %s.\n", candidates[i].name);
                        break;
                    }
                }
                break;
            case 2:
                printf("The results are:\n");
                for (i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;
            case 3:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}