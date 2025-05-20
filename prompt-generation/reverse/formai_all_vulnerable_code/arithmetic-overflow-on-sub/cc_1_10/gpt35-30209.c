//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    printf("Oh, dear friend, let me introduce myself\n");
    printf("I am a music lover, and I need your help\n");
    printf("A library to store my music collection\n");
    printf("A system to manage every song's section\n");

    int songCount = 0;
    int i;

    printf("I have gathered %d songs about love\n", songCount);

    printf("But first, let me tell you about Romeo and Juliet\n");
    printf("A tale of passion and a love that they couldn't quit\n");
    printf("If only they had a music library at hand\n");
    printf("Perhaps their love could have withstood all commands\n");

    printf("They could have organized their music by mood\n");
    printf("For when they felt happy, when they felt blue\n");

    char moods[][20] = {"happy", "sad", "romantic", "energetic", "relaxing"};

    printf("Here are the available moods:\n");

    for(i=0; i<5; i++) {
        printf("%d. %s\n", i+1, moods[i]);
    }

    int moodChoice;
    printf("Choose a mood for your music: ");
    scanf("%d", &moodChoice);

    printf("You have selected %s music\n", moods[moodChoice-1]);

    printf("Songs fitting your mood:\n");
    // Here you can query a database with your music collections

    songCount = 5;

    char songs[][60] = {"Love Story - Taylor Swift",
                        "Thinking Out Loud - Ed Sheeran",
                        "My Heart Will Go On - Celine Dion",
                        "All Of Me - John Legend",
                        "I Will Always Love You - Whitney Houston"};

    for(i=0; i<songCount; i++) {
        printf("%d. %s\n", i+1, songs[i]);
    }

    return 0;
}