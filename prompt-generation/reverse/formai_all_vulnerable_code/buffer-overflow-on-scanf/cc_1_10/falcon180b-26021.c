//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char date[10];
    char mood[20];
    char activity[50];
} Entry;

void add_entry(Entry* diary, int num_entries, char* date, char* mood, char* activity) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].mood, mood);
    strcpy(diary[num_entries].activity, activity);
    num_entries++;
}

void print_entries(Entry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\n", diary[i].date, diary[i].mood, diary[i].activity);
    }
}

int main() {
    int num_entries = 0;
    Entry diary[100];
    char date[10];
    char mood[20];
    char activity[50];

    time_t now = time(0);
    struct tm* local_time = localtime(&now);
    strftime(date, 10, "%Y-%m-%d", local_time);

    while (1) {
        printf("Enter your mood for today (e.g. happy, sad, tired): ");
        scanf("%s", mood);
        tolower(mood);

        printf("Enter your activity for today (e.g. work, school, exercise): ");
        scanf("%s", activity);

        add_entry(diary, num_entries, date, mood, activity);
        num_entries++;

        printf("\nWould you like to add another entry? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    printf("\nYour diary entries:\n");
    print_entries(diary, num_entries);

    return 0;
}