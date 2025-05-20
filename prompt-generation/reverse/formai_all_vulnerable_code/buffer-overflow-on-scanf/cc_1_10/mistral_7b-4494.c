//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VOTERS 10000
#define MAX_OPTIONS 5
#define VOTE_FILE "votes.bin"

typedef struct {
    char name[50];
    int vote[MAX_OPTIONS];
} Voter;

void encrypt_file(FILE *input, FILE *output) {
    int key = 0xDEADBEEF;
    char c;

    while ((c = fgetc(input)) != EOF) {
        fputc(c ^ key, output);
    }
}

void decrypt_file(FILE *input, FILE *output) {
    int key = 0xDEADBEEF;
    char c;

    while ((c = fgetc(input)) != EOF) {
        fputc(c ^ key, output);
    }
}

int main() {
    FILE *votes_file, *temp_file;
    Voter voters[MAX_VOTERS];
    int i, j, option, encrypted = 1;

    srand(time(NULL));

    if ((votes_file = fopen(VOTE_FILE, "rb")) != NULL) {
        decrypt_file(votes_file, temp_file = fopen("temp.bin", "wb"));
        fclose(votes_file);
        fclose(temp_file);
        remove(VOTE_FILE);
        rename("temp.bin", VOTE_FILE);
    }

    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Voter %d, please enter your name: ", i + 1);
        scanf("%s", voters[i].name);

        printf("Voter %d, please choose your preferred option among %d:\n", i + 1, MAX_OPTIONS);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: ", j + 1);
            scanf("%d", &option);
            voters[i].vote[j] = option;
        }
    }

    if ((votes_file = fopen(VOTE_FILE, "ab")) != NULL) {
        for (i = 0; i < MAX_VOTERS; i++) {
            fwrite(&voters[i], sizeof(Voter), 1, votes_file);
        }
        fclose(votes_file);

        encrypt_file(fopen(VOTE_FILE, "rb"), fopen("encrypted.bin", "wb"));
        remove(VOTE_FILE);
        rename("encrypted.bin", VOTE_FILE);
    }

    printf("\nThe voting process has been completed.\n");
    printf("The encrypted votes file has been saved.\n");

    return 0;
}