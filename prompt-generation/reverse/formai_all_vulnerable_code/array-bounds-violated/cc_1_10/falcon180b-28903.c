//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger."},
    {"A great opportunity is coming your way."},
    {"Your lucky numbers are 7, 13, 42 and 99."},
    {"Beware of a friend who is not what they seem."},
    {"You will find true love in the most unexpected place."},
    {"A long-lost relative will soon contact you."},
    {"Your hard work will finally pay off."},
    {"Travel is in your future, perhaps to a far-off land."},
    {"You will receive an unexpected gift."},
    {"A new hobby will bring you great joy."}
};

void generate_fortune(Fortune* fortune) {
    int i;
    char* nouns[] = {"love", "money", "success", "happiness", "friendship", "health", "adventure", "knowledge", "wisdom", "peace"};
    char* verbs[] = {"find", "achieve", "discover", "attain", "gain", "receive", "encounter", "learn", "realize", "experience"};
    char* articles[] = {"a", "an", "the", "your", "my", "his", "her", "its", "our", "their"};
    char* prepositions[] = {"in", "at", "on", "with", "to", "from", "by", "for", "into", "through"};
    char* conjunctions[] = {"and", "or", "but", "yet", "so", "for", "nor", "although", "while", "since"};

    srand(time(NULL));
    i = rand() % 10; // choose random noun
    strcpy(fortune->text, articles[rand() % 11]);
    strcat(fortune->text, " ");
    strcat(fortune->text, nouns[i]);
    strcat(fortune->text, " ");
    i = rand() % 10; // choose random verb
    strcat(fortune->text, " ");
    strcat(fortune->text, verbs[i]);
    strcat(fortune->text, " ");
    i = rand() % 10; // choose random preposition
    strcat(fortune->text, " ");
    strcat(fortune->text, prepositions[i]);
    strcat(fortune->text, " ");
    i = rand() % 10; // choose random conjunction
    strcat(fortune->text, " ");
    strcat(fortune->text, conjunctions[i]);
    strcat(fortune->text, " ");
    i = rand() % 10; // choose random noun
    strcat(fortune->text, " ");
    strcat(fortune->text, nouns[i]);
    strcat(fortune->text, ".");
}

int main() {
    int choice, num_fortunes;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &num_fortunes);

    srand(time(NULL));
    for (int i = 0; i < num_fortunes; i++) {
        generate_fortune(&fortunes[i]);
        printf("\n%s\n", fortunes[i].text);
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");
    return 0;
}