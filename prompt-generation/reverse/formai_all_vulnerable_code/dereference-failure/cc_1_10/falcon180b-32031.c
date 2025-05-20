//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100
#define MAX_CONSPIRACY_LENGTH 50

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

typedef struct {
    char *subject;
    char *verb;
    char *object;
    char *preposition;
    char *article;
    char *adjective;
    char *noun;
} Sentence;

Person *generate_person() {
    Person *person = (Person *) malloc(sizeof(Person));

    person->name = (char *) malloc(MAX_WORDS * sizeof(char));
    person->age = rand() % 100;
    person->occupation = (char *) malloc(MAX_WORDS * sizeof(char));

    sprintf(person->name, "John Doe");
    sprintf(person->occupation, "Software Engineer");

    return person;
}

Sentence *generate_sentence(char *subject, char *verb, char *object) {
    Sentence *sentence = (Sentence *) malloc(sizeof(Sentence));

    sentence->subject = (char *) malloc(MAX_WORDS * sizeof(char));
    sentence->verb = (char *) malloc(MAX_WORDS * sizeof(char));
    sentence->object = (char *) malloc(MAX_WORDS * sizeof(char));

    strcpy(sentence->subject, subject);
    strcpy(sentence->verb, verb);
    strcpy(sentence->object, object);

    return sentence;
}

void generate_conspiracy(char *conspiracy, int length) {
    char *words[] = {"government", "aliens", "illuminati", "chemtrails", "9/11", "moon landing", "JFK", "area 51", "vaccines", "flat earth"};

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        conspiracy[i] = words[rand() % sizeof(words) / sizeof(words[0])][rand() % strlen(words[rand() % sizeof(words) / sizeof(words[0])])];
    }

    conspiracy[length] = '\0';
}

int main() {
    Person *person = generate_person();
    Sentence *sentence = generate_sentence("John Doe", "works for", "the government");
    char conspiracy[MAX_CONSPIRACY_LENGTH];

    printf("John Doe, a %s-year-old software engineer, %s.\n", person->age, sentence->verb);
    printf("The conspiracy theory is: %s\n", conspiracy);

    return 0;
}