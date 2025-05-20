//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char text[80];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will have a great day today!", 34},
    {"A surprise is waiting for you around the corner.", 50},
    {"You will meet someone special soon.", 29},
    {"Your hard work will pay off.", 32},
    {"Take a chance, it might lead to something amazing.", 51},
    {"Don't be afraid to dream big.", 28},
    {"The future holds many possibilities for you.", 39},
    {"Success is within reach, keep pushing forward.", 42},
    {"Believe in yourself and all that you are.", 45},
    {"You are capable of achieving greatness.", 41}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[80];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What would you like to know?\n");
    printf("1. Love\n2. Career\n3. Future\n4. General\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("What's on your mind about love?\n");
            scanf("%s", input);
            printf("Your fortune: %s\n", fortunes[0].text);
            break;
        case 2:
            printf("What's on your mind about your career?\n");
            scanf("%s", input);
            printf("Your fortune: %s\n", fortunes[1].text);
            break;
        case 3:
            printf("What's on your mind about the future?\n");
            scanf("%s", input);
            printf("Your fortune: %s\n", fortunes[2].text);
            break;
        case 4:
            printf("What would you like to know about the future?\n");
            scanf("%s", input);
            int index = rand() % MAX_FORTUNES;
            printf("Your fortune: %s\n", fortunes[index].text);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}