//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIARY_SIZE 30

typedef struct {
    char name[20];
    int day;
    int year;
} medieval_diary;

void medieval_diary_entry(char* name, int day, int year) {
    printf("\nIn the hall of this keep, on the yerde of the %d day,\n", day);
    printf("in the yere of our Lorde %d,\n", year);
    printf("was penned this tale by the hand of %s:\n\n", name);
}

int main() {
    srand(time(NULL));

    medieval_diary diary[DIARY_SIZE];

    for (int i = 0; i < 20; i++) {
        int name_length = rand() % 10 + 5;
        char name[name_length];

        for (int j = 0; j < name_length; j++) {
            name[j] = 'A' + (rand() % 26);
        }

        name[name_length] = '\0';

        int day = rand() % 31 + 1;
        int year = rand() % 1000 + 1200;

        medieval_diary_entry(name, day, year);

        strcpy(diary[i].name, name);
        diary[i].day = day;
        diary[i].year = year;
    }

    printf("\n----- The Medieval Diary ------\n");
    for (int i = 0; i < 20; i++) {
        printf("\nIn the hall of this keep, on the yerde of the %d day,\n", diary[i].day);
        printf("in the yere of our Lorde %d,\n", diary[i].year);
        printf("was penned this tale by the hand of %s:\n\n", diary[i].name);
    }

    return 0;
}