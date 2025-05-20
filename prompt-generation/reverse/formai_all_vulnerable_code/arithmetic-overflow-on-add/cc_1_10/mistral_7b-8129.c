//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int year;
    char* message;
} Oracle;

Oracle oracles[13] = {
    {1923, "Thy journey begins in fire, end in water."},
    {1924, "In shadows, thy truth is hidden, seek in light."},
    {1925, "Thine heart shall be a temple, guard it well."},
    {1926, "Two roads diverged, choose wisely, travel far."},
    {1927, "The path of gold leads to the heart of the storm."},
    {1928, "Beware the serpent's gaze, trust not its false charm."},
    {1929, "The moon whispers secrets, listen close, in dreams."},
    {1930, "The gatekeepers guard the gate, but thy destiny awaits."},
    {1931, "Born of water, thy spirit shall rise above all."},
    {1932, "Thy heart is a garden, nurture it with care."},
    {1933, "The stars align for thee, seize the moment, embrace thy fate."},
    {1934, "The river of time flows ever onward, join it in its dance."},
    {0, NULL}
};

void get_oracle(int birth_year) {
    int i;
    Oracle* current;

    for (i = 0; oracles[i].year != 0; i++) {
        current = &oracles[i];
        if (current->year == birth_year) {
            printf("%s\n", current->message);
            return;
        }
    }

    printf("No oracle found for your birth year.\n");
}

int main(int argc, char** argv) {
    int birth_year;
    time_t t;
    struct tm* birthday;

    if (argc != 2) {
        printf("Usage: %s <birth year>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d", &birth_year);
    time(&t);
    birthday = localtime(&t);
    birthday->tm_year += 1900;

    if (birthday->tm_year != birth_year) {
        printf("Invalid birth year.\n");
        return 1;
    }

    get_oracle(birth_year);

    return 0;
}