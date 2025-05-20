//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char text[80];
    char keyword[20];
} fortune;

void load_fortunes(fortune fortunes[]) {
    FILE *file = fopen("fortunes.txt", "r");
    int count = 0;
    if (file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }
    while (fscanf(file, "%s %s\n", fortunes[count].text, fortunes[count].keyword)!= EOF && count < MAX_FORTUNES) {
        count++;
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    fortune fortunes[MAX_FORTUNES];
    load_fortunes(fortunes);
    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            char input[80];
            printf("Enter a keyword or phrase:\n");
            scanf("%s", input);
            int match_count = 0;
            for (int i = 0; i < MAX_FORTUNES; i++) {
                if (strstr(fortunes[i].text, input)!= NULL || strstr(fortunes[i].keyword, input)!= NULL) {
                    printf("%s\n", fortunes[i].text);
                    match_count++;
                }
            }
            if (match_count == 0) {
                printf("No fortunes found for that keyword or phrase.\n");
            }
        }
    } while (choice!= 2);
    return 0;
}