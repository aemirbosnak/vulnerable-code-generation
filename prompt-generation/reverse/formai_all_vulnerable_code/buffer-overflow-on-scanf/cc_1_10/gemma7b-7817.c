//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Scene: The fog-laden streets of London. The year is 1890. Sherlock Holmes and Dr. Watson are investigating a mysterious case.

    // Characters:
    // - Mr. Bartholomew, a wealthy businessman, found dead in his apartment.
    // - Mr. Jennings, a suspicious landlord.
    // - Mrs. Jennings, Mr. Jennings' wife.
    // - Mr. Peterson, a detective.

    // Evidence:
    // - A broken window.
    // - A bloodstained letter.
    // - A mysterious key.

    // Begin by gathering information from the scene.
    printf("What is the name of the deceased gentleman?\n");
    char deceased_name[20];
    scanf("%s", deceased_name);

    // Inspect the broken window.
    printf("Did the window appear to be broken from the outside or inside the apartment?\n");
    char window_direction[20];
    scanf("%s", window_direction);

    // Analyze the bloodstained letter.
    printf("What was the content of the bloodstained letter?\n");
    char letter_content[200];
    scanf("%s", letter_content);

    // Examine the mysterious key.
    printf("What is the description of the mysterious key?\n");
    char key_description[200];
    scanf("%s", key_description);

    // Now, use your deductive reasoning to solve the case.
    // What is the cause of Mr. Bartholomew's death?
    char cause_of_death[200];
    scanf("%s", cause_of_death);

    // Conclude the case.
    printf("The mystery is solved. Mr. Bartholomew was murdered by...\n");
    char killer_name[20];
    scanf("%s", killer_name);

    // Print the results of your investigation.
    printf("The deceased was: %s\n", deceased_name);
    printf("The cause of death was: %s\n", cause_of_death);
    printf("The killer was: %s\n", killer_name);

    return 0;
}