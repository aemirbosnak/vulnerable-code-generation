//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char name[20];
    int atomic_no;
    char symbol[10];
    int valency;
    int correct_ans = 0;
    int total_ans = 0;
    int score = 0;
    int i = 0;

    printf("Periodic Table Quiz\n");

    while(1) {
        printf("\n1. Start Quiz\n2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter your name: ");
            scanf("%s", name);

            printf("\nWelcome, %s. Let's start the quiz!\n", name);

            for(i = 1; i <= 10; i++) {
                atomic_no = rand() % 120 + 1;
                if(atomic_no == 1) {
                    strcpy(symbol, "H");
                }
                else if(atomic_no == 6) {
                    strcpy(symbol, "C");
                }
                else if(atomic_no == 7) {
                    strcpy(symbol, "N");
                }
                else if(atomic_no == 8) {
                    strcpy(symbol, "O");
                }
                else if(atomic_no == 79) {
                    strcpy(symbol, "Au");
                }
                else {
                    sprintf(symbol, "%d", atomic_no);
                }

                printf("\n%d. %s - %s\n", i, symbol, name);

                scanf("%s", symbol);

                if(strcmp(symbol, name) == 0) {
                    correct_ans++;
                }

                total_ans++;
            }

            score = (correct_ans * 100) / total_ans;

            printf("\nYour score is: %d%%\n", score);

            break;
        }
        else if(choice == 2) {
            printf("\nThank you, %s, for playing the quiz!\n", name);
            exit(0);
        }
        else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}