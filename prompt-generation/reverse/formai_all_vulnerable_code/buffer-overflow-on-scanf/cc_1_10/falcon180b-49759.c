//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will meet someone new today. ", 28},
    {"A pleasant surprise awaits you. ", 34},
    {"You will be successful in your endeavors. ", 41},
    {"A friend will offer you help when you need it most. ", 45},
    {"You will find happiness in unexpected places. ", 32},
    {"Your hard work will pay off soon. ", 31},
    {"A new opportunity will present itself to you. ", 39},
    {"You will experience a moment of pure joy. ", 28},
    {"A loved one will reach out to you. ", 31},
    {"You will receive good news. ", 24}
};

void print_fortune(fortune* f) {
    printf("%s\n", f->text);
}

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to tell you your fortune.\n", input);

    while(1) {
        printf("Please choose a fortune:\n");
        for(int i=0; i<MAX_FORTUNES; i++) {
            printf("%d. %s\n", i+1, fortunes[i].text);
        }
        printf("0. Exit\n");
        scanf("%d", &choice);

        if(choice == 0) {
            break;
        } else if(choice > 0 && choice <= MAX_FORTUNES) {
            print_fortune(&fortunes[choice-1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}