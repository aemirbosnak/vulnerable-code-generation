//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generate_poem(char* name);

int main() {
    char name[50];

    // Get user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // Generate a romantic poem for the user
    generate_poem(name);

    return 0;
}

// Generate a romantic poem using the given name
void generate_poem(char* name) {
    char poem[200];
    int i, j, k;

    // Initialize the poem with a romantic message
    strcpy(poem, "Roses are red,\n");
    strcat(poem, "Violets are blue,\n");
    strcat(poem, "I'm so in love with you.\n");
    strcat(poem, "\n");

    // Add some personalized lines to the poem
    strcat(poem, "Your eyes sparkle like stars above,\n");
    strcat(poem, "Your smile warms my heart like a dove.\n");
    strcat(poem, "With you by my side, life is complete,\n");
    strcat(poem, "My love for you will never deplete.\n");

    // Add some random romantic words to the poem
    for (i = 0; i < 3; i++) {
        j = rand() % 6;
        switch (j) {
            case 0:
                strcat(poem, "Passionate kisses under the moonlit sky,\n");
                break;
            case 1:
                strcat(poem, "Whispers of love as we lay side by side,\n");
                break;
            case 2:
                strcat(poem, "Endless nights of passion, you and I,\n");
                break;
            case 3:
                strcat(poem, "Your touch sends shivers down my spine,\n");
                break;
            case 4:
                strcat(poem, "Together forever, our hearts intertwine,\n");
                break;
            case 5:
                strcat(poem, "In your arms, I feel safe and divine.\n");
                break;
        }
    }

    // Print the final poem
    printf("A romantic poem for %s:\n%s", name, poem);
}