//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char input[MAX_ENTRY_LENGTH];
    char *word;
    time_t now;

    srand(time(NULL));
    now = time(NULL);

    for (int i = 0; i < MAX_ENTRIES; i++) {
        diary[i].timestamp = now - i * 3600 * 24;
    }

    while (1) {
        printf("Enter your thoughts for today (max %d characters):\n", MAX_ENTRY_LENGTH - 1);
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        word = strtok(input, " ");
        while (word!= NULL) {
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full. Cannot add more entries.\n");
                break;
            }

            int j;
            for (j = 0; j < num_entries; j++) {
                if (diary[j].timestamp == now) {
                    strcat(diary[j].text, " ");
                    strcat(diary[j].text, word);
                    break;
                }
            }

            if (j == num_entries) {
                diary[num_entries].timestamp = now;
                strcpy(diary[num_entries].text, word);
                num_entries++;
            }

            word = strtok(NULL, " ");
        }
    }

    return 0;
}