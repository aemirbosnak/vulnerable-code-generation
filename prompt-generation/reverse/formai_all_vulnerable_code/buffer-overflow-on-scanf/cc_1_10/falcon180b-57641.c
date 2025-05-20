//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} fortune_t;

fortune_t fortunes[MAX_FORTUNES] = {
    {"You will meet someone new today."},
    {"A great opportunity is coming your way."},
    {"Your hard work will pay off soon."},
    {"You will have a lucky day."},
    {"A friend will need your help."},
    {"You will receive good news."},
    {"You will overcome a challenge."},
    {"You will find what you have been looking for."},
    {"You will have a successful trip."},
    {"You will have a pleasant surprise."}
};

int main() {
    srand(time(NULL));
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int fortune_index;
    char choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will tell you your fortune based on your choices.\n");
    printf("Please enter your name: ");
    scanf("%s", &choice);

    printf("\n%s, I am pleased to meet you!\n", choice);
    printf("What would you like to know about your future?\n");
    printf("1. Love\n2. Career\n3. Health\n4. Money\n5. Travel\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYour love life will be...\n");
            fortune_index = rand() % num_fortunes;
            printf("%s\n", fortunes[fortune_index].text);
            break;
        case 2:
            printf("\nYour career will be...\n");
            fortune_index = rand() % num_fortunes;
            printf("%s\n", fortunes[fortune_index].text);
            break;
        case 3:
            printf("\nYour health will be...\n");
            fortune_index = rand() % num_fortunes;
            printf("%s\n", fortunes[fortune_index].text);
            break;
        case 4:
            printf("\nYour finances will be...\n");
            fortune_index = rand() % num_fortunes;
            printf("%s\n", fortunes[fortune_index].text);
            break;
        case 5:
            printf("\nYour travels will be...\n");
            fortune_index = rand() % num_fortunes;
            printf("%s\n", fortunes[fortune_index].text);
            break;
        default:
            printf("\nSorry, I cannot predict the future in that category.\n");
            break;
    }

    return 0;
}