//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THOUGHTS 50
#define MAX_FEELINGS 50

struct thought {
    char *text;
    char *emotion;
};

struct feelings {
    char *name;
    char *description;
};

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    // Initialize thoughts and feelings arrays
    struct thought thoughts[MAX_THOUGHTS];
    struct feelings feelings[MAX_FEELINGS];
    int i, j;

    // Ask user for thoughts and feelings
    for (i = 0; i < MAX_THOUGHTS; i++) {
        printf("What's on your mind?\n");
        fgets(thoughts[i].text, 100, stdin);
        thoughts[i].emotion = strtok(thoughts[i].text, " ");

        // Add thought to the array
        thoughts[i].text[strcspn(thoughts[i].text, "\n")] = 0;
    }

    for (j = 0; j < MAX_FEELINGS; j++) {
        printf("How are you feeling today?\n");
        fgets(feelings[j].name, 50, stdin);
        feelings[j].description = strtok(feelings[j].name, " ");
    }

    // Generate poetic and artistic responses
    for (i = 0; i < MAX_THOUGHTS; i++) {
        for (j = 0; j < MAX_FEELINGS; j++) {
            // Use a combination of the thought and feeling to generate a response
            char *response = NULL;
            if (strstr(thoughts[i].emotion, "happy")) {
                if (strstr(feelings[j].description, "love")) {
                    response = "Your heart is filled with love and joy, like a sunny day in a field of daisies.";
                } else if (strstr(feelings[j].description, "laughter")) {
                    response = "Your laughter is contagious, spreading happiness like a wildfire in a forest.";
                }
            } else if (strstr(thoughts[i].emotion, "sad")) {
                if (strstr(feelings[j].description, "tears")) {
                    response = "Your tears are like the rain, washing away the pain and leaving you fresh and clean.";
                } else if (strstr(feelings[j].description, "longing")) {
                    response = "Your heart is heavy with longing, like a raven's call in the night.";
                }
            }

            // Print the response
            printf("%s\n", response);
        }
    }

    return 0;
}