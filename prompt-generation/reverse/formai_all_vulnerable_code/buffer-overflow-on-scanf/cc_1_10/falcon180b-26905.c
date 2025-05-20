//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10

void shuffle(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    char name[30];
    int choice, num;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nWelcome to the Automated Fortune Teller, %s!\n", name);
    printf("I can predict your love life, career, or health.\n");
    printf("Which aspect of your life would you like me to predict?\n");
    printf("1. Love Life\n2. Career\n3. Health\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nI can predict your love life.\n");
            printf("Enter the number of predictions you want: ");
            scanf("%d", &num);
            printf("\nLet me shuffle the cards...\n");
            int cards[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            shuffle(cards, num);
            for (int i = 0; i < num; i++) {
                printf("\nCard %d: %d\n", i+1, cards[i]);
            }
            break;
        case 2:
            printf("\nI can predict your career.\n");
            printf("Enter the number of predictions you want: ");
            scanf("%d", &num);
            printf("\nLet me shuffle the cards...\n");
            int cards_career[MAX] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
            shuffle(cards_career, num);
            for (int i = 0; i < num; i++) {
                printf("\nCard %d: %d\n", i+1, cards_career[i]);
            }
            break;
        case 3:
            printf("\nI can predict your health.\n");
            printf("Enter the number of predictions you want: ");
            scanf("%d", &num);
            printf("\nLet me shuffle the cards...\n");
            int cards_health[MAX] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
            shuffle(cards_health, num);
            for (int i = 0; i < num; i++) {
                printf("\nCard %d: %d\n", i+1, cards_health[i]);
            }
            break;
        default:
            printf("\nInvalid choice.\n");
    }
    return 0;
}