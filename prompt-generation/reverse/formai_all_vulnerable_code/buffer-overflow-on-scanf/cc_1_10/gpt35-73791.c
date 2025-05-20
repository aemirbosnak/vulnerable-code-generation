//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int rating;
    char choice;

    printf("O Romeo, O Romeo, what shall thou rate this movie? (1-5 stars)\n");
    scanf("%d", &rating);

    if (rating == 1) {
        printf("Alas, this movie doth not deserve thine attention. Shall I fetch thee another film? (y/n)\n");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("Very well, let me suggest 'The Godfather'.\n");
        } else {
            printf("As thy wish, good sir.\n");
        }
    } else if (rating == 2) {
        printf("This movie hath some merit, but mayhaps thou might prefer a different genre? (y/n)\n");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("Perhaps 'Jurassic Park' may better suit thy tastes.\n");
        } else {
            printf("Understood, my lord.\n");
        }
    } else if (rating == 3) {
        printf("Ah, a middle-of-the-road movie. May I suggest some refreshments to enhance thy viewing experience? (y/n)\n");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("Shall I bring thee some popcorn and soda?\n");
        } else {
            printf("Very well, my liege.\n");
        }
    } else if (rating == 4) {
        printf("Verily, this movie is a fine specimen. Shall I recommend it to our Royal Society of Cinema? (y/n)\n");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("Of course, my lord. Your recommendation shall be made known.\n");
        } else {
            printf("As you wish, my lord.\n");
        }
    } else {
        printf("By my troth, this movie is a masterpiece! Shall I schedule an encore viewing? (y/n)\n");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("As you command, my lord. I shall arrange another screening of this magnum opus.\n");
        } else {
            printf("Very well, my lord. I shall not disturb thy cinematic pleasures further.\n");
        }
    }

    return 0;
}