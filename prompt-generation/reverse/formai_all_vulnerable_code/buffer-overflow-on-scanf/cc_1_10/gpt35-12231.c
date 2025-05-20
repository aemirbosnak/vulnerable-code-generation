//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>

int main() {
    // define the initial quiz question and answer
    char question[] = "What is the symbol for Carbon?";
    char answer[] = "C";

    // initialize the user's response
    char response[10];

    // define the shape-shifting element
    char element[] = "Carbon";

    // define the possible alternate forms of the element
    char diamond[] = "Diamond";
    char charcoal[] = "Charcoal";
    char graphite[] = "Graphite";

    // print the quiz question
    printf("%s\n", question);

    // receive the user's response
    scanf("%s", response);

    // check if the response is correct
    if (strcmp(response, answer) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s\n", answer);
    }

    // shuffle the element and alternate forms
    int shuffle_index = rand() % 4;
    switch (shuffle_index) {
        case 0:
            strcpy(element, diamond);
            strcpy(diamond, charcoal);
            strcpy(charcoal, graphite);
            strcpy(graphite, "Carbon");
            break;
        case 1:
            strcpy(element, charcoal);
            strcpy(charcoal, graphite);
            strcpy(graphite, diamond);
            strcpy(diamond, "Carbon");
            break;
        case 2:
            strcpy(element, graphite);
            strcpy(graphite, diamond);
            strcpy(diamond, charcoal);
            strcpy(charcoal, "Carbon");
            break;
        case 3:
            // the element does not change
            break;
    }

    // print the shape-shifting element and alternate forms
    printf("%s can also take the form of:\n", element);
    printf("- %s\n", diamond);
    printf("- %s\n", charcoal);
    printf("- %s\n", graphite);

    // ask the user which alternate form they want to learn more about
    printf("Which form of %s would you like to learn more about? (enter either Diamond, Charcoal, or Graphite)\n", element);
    char alternate_response[10];
    scanf("%s", alternate_response);

    // provide information about the chosen alternate form
    if (strcmp(alternate_response, diamond) == 0) {
        printf("%s is a form of %s that is used in jewelry and cutting tools.\n", diamond, element);
    } else if (strcmp(alternate_response, charcoal) == 0) {
        printf("%s is a form of %s that is used in cooking, heating, and drawing.\n", charcoal, element);
    } else if (strcmp(alternate_response, graphite) == 0) {
        printf("%s is a form of %s that is used in pencils, lubricants, and batteries.\n", graphite, element);
    } else {
        printf("Invalid response. Please enter either Diamond, Charcoal, or Graphite.\n");
    }

    return 0;
}