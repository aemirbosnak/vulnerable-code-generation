//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define FILE_NAME "votes.txt"
#define MAX_URL_LENGTH 256

typedef struct {
    char url[MAX_URL_LENGTH];
    int upvotes;
    int downvotes;
} VoteRecord;

void cast_vote(VoteRecord *record, int vote) {
    if (vote > 0) {
        record->upvotes++;
        printf("You upvoted: %s\n", record->url);
    } else {
        record->downvotes++;
        printf("You downvoted: %s\n", record->url);
    }
}

void save_votes(VoteRecord *records, int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %d\n", records[i].url, records[i].upvotes, records[i].downvotes);
    }
    fclose(file);
    printf("Votes saved to %s\n", FILE_NAME);
}

void load_votes(VoteRecord *records, int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    while (fscanf(file, "%s %d %d\n", records[*count].url, &records[*count].upvotes, &records[*count].downvotes) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void display_votes(VoteRecord *records, int count) {
    printf("\nCurrent votes:\n");
    for (int i = 0; i < count; i++) {
        printf("URL: %s | Upvotes: %d | Downvotes: %d\n", records[i].url, records[i].upvotes, records[i].downvotes);
    }
}

int main() {
    VoteRecord records[100] = {0}; // max 100 records
    int count = 0;

    load_votes(records, &count);

    while (1) {
        char input[MAX_URL_LENGTH + 10];
        printf("\nEnter URL to vote (format: URL VOTE) or 'exit' to quit:\n");
        printf("Usage: http://example.com up (to upvote) or http://example.com down (to downvote)\n");
        fgets(input, sizeof(input), stdin);
        
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        char url[MAX_URL_LENGTH];
        int vote = 0;

        if (sscanf(input, "%s %s", url, input) == 2) {
            if (strcasecmp(input, "up") == 0) {
                vote = 1; // upvote
            } else if (strcasecmp(input, "down") == 0) {
                vote = -1; // downvote
            } else {
                printf("Invalid vote! Use 'up' or 'down'.\n");
                continue;
            }

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(records[i].url, url) == 0) {
                    cast_vote(&records[i], vote);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strcpy(records[count].url, url);
                records[count].upvotes = 0;
                records[count].downvotes = 0;
                cast_vote(&records[count], vote);
                count++;
            }

            display_votes(records, count);
            save_votes(records, count);
        } else {
            printf("Error reading input. Please follow the correct format.\n");
        }
    }

    return 0;
}