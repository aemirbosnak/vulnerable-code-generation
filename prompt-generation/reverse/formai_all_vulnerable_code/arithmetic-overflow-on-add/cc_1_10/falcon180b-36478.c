//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_FORTUNE 50
#define MAX_LENGTH 200

typedef struct {
    char text[MAX_LENGTH];
    char fortune[MAX_LENGTH];
} fortune_t;

fortune_t fortunes[MAX_FORTUNE] = {
    {"You will meet a tall, dark stranger.","romance"},
    {"You will come into a large sum of money.","wealth"},
    {"You will travel to exotic places.","travel"},
    {"You will have good health and long life.","health"},
    {"You will have a successful career.","success"},
    {"You will find true love.","love"},
    {"You will have many children.","family"},
    {"You will be famous.","fame"},
    {"You will have a happy home life.","home"},
    {"You will have good luck in all your endeavors.","luck"}
};

void generate_fortune(char* fortune_text) {
    srand(time(NULL));
    int index = rand() % MAX_FORTUNE;
    strcpy(fortune_text, fortunes[index].fortune);
}

int main() {
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nHello %s,\n", name);
    printf("I am the Automated Fortune Teller.\n");
    printf("I will tell you your fortune.\n");
    printf("Please enter your date of birth (dd/mm/yyyy): ");
    char dob[11];
    scanf("%s", dob);

    int day, month, year;
    sscanf(dob, "%d/%d/%d", &day, &month, &year);
    int age = (year - 1900) * 365 + (month - 1) * 30 + day - 1;

    if(age < 0) {
        printf("\nInvalid date of birth.\n");
        return 1;
    }

    printf("\nYour age is %d years.\n", age);

    char fortune_text[MAX_LENGTH];
    generate_fortune(fortune_text);

    printf("\nYour fortune is:\n%s\n", fortune_text);

    return 0;
}