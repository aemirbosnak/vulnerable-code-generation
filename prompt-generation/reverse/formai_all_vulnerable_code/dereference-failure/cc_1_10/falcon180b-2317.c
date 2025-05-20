//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *subject;
    char *verb;
    char *object;
} ConspiracyTheory;

ConspiracyTheory generate_theory() {
    ConspiracyTheory theory;
    theory.subject = (char*)malloc(20*sizeof(char));
    theory.verb = (char*)malloc(20*sizeof(char));
    theory.object = (char*)malloc(20*sizeof(char));

    srand(time(NULL));
    int subject_index = rand() % 5;
    int verb_index = rand() % 5;
    int object_index = rand() % 5;

    switch(subject_index) {
        case 0:
            strcpy(theory.subject, "The government");
            break;
        case 1:
            strcpy(theory.subject, "Big corporations");
            break;
        case 2:
            strcpy(theory.subject, "Aliens");
            break;
        case 3:
            strcpy(theory.subject, "Secret societies");
            break;
        case 4:
            strcpy(theory.subject, "Time travelers");
            break;
    }

    switch(verb_index) {
        case 0:
            strcpy(theory.verb, "is hiding");
            break;
        case 1:
            strcpy(theory.verb, "has been controlling");
            break;
        case 2:
            strcpy(theory.verb, "is planning");
            break;
        case 3:
            strcpy(theory.verb, "is manipulating");
            break;
        case 4:
            strcpy(theory.verb, "has infiltrated");
            break;
    }

    switch(object_index) {
        case 0:
            strcpy(theory.object, "the truth about extraterrestrial life");
            break;
        case 1:
            strcpy(theory.object, "the cure for cancer");
            break;
        case 2:
            strcpy(theory.object, "the real reason for climate change");
            break;
        case 3:
            strcpy(theory.object, "the secret to eternal life");
            break;
        case 4:
            strcpy(theory.object, "the location of Atlantis");
            break;
    }

    return theory;
}

void print_theory(ConspiracyTheory theory) {
    printf("%s %s %s.\n", theory.subject, theory.verb, theory.object);
}

int main() {
    ConspiracyTheory theory = generate_theory();
    print_theory(theory);
    return 0;
}