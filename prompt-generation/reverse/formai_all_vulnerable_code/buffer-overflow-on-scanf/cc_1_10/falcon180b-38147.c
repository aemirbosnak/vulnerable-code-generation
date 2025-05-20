//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80
#define MAX_USER_NAME_LENGTH 20

struct fortune {
    char text[MAX_FORTUNE_LENGTH];
    int length;
};

void read_fortunes(struct fortune fortunes[]) {
    FILE *fp;
    int i = 0;

    fp = fopen("fortunes.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open fortunes file.\n");
        exit(1);
    }

    while (fgets(fortunes[i].text, MAX_FORTUNE_LENGTH, fp)!= NULL) {
        fortunes[i].length = strlen(fortunes[i].text);
        i++;
    }

    fclose(fp);
}

void print_fortune(struct fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    char user_name[MAX_USER_NAME_LENGTH];
    struct fortune fortunes[NUM_FORTUNES];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", user_name);

    read_fortunes(fortunes);

    srand(time(NULL));
    int fortune_index = rand() % NUM_FORTUNES;

    printf("\n");
    printf("Dear %s,\n", user_name);
    printf("Your fortune is:\n");
    print_fortune(fortunes[fortune_index]);

    return 0;
}