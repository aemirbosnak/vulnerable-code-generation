//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

struct intrusion {
    char date[20];
    char time[20];
    char type[20];
    char message[100];
};

void add_intrusion(struct intrusion *intr) {
    printf("Enter intrusion date (dd/mm/yyyy): ");
    scanf("%s", intr->date);
    printf("Enter intrusion time (hh:mm:ss): ");
    scanf("%s", intr->time);
    printf("Enter intrusion type: ");
    scanf("%s", intr->type);
    printf("Enter intrusion message: ");
    scanf(" %[^\n]s", intr->message);
    count++;
}

void print_intrusions(struct intrusion *intr, int n) {
    printf("Date\t\tTime\t\tType\t\tMessage\n");
    printf("------------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t%s\t%s\n", intr[i].date, intr[i].time, intr[i].type, intr[i].message);
    }
}

void clear_intrusions(struct intrusion *intr, int n) {
    memset(intr, 0, sizeof(struct intrusion) * n);
    count = 0;
}

int main() {
    struct intrusion *intrusions;
    int option=0, n=0;

    printf("Welcome to the Intrusion Detection System!\n");

    while(option != 4) {
        printf("\nChoose an option:\n");
        printf("1. Add an intrusion\n");
        printf("2. View all intrusions\n");
        printf("3. Clear all intrusions\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(count >= n) {
                    printf("\nEnter the number of intrusions you want to store: ");
                    scanf("%d", &n);
                    intrusions = (struct intrusion *) malloc(sizeof(struct intrusion) * n);
                }
                add_intrusion(&intrusions[count]);
                break;
            case 2:
                if(count == 0) {
                    printf("\nNo intrusions found.\n");
                } else {
                    print_intrusions(intrusions, count);
                }
                break;
            case 3:
                clear_intrusions(intrusions, n);
                printf("\nAll intrusions cleared.\n");
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }
    }

    free(intrusions);
    return 0;
}