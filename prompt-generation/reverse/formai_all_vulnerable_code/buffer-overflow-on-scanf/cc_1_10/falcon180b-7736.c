//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

struct fortune {
    char *text;
    int length;
};

void print_fortune(struct fortune *fortune) {
    printf("\n%s\n", fortune->text);
}

int main() {
    srand(time(NULL));

    struct fortune fortunes[NUM_FORTUNES] = {
        { "Thou shalt find great wealth in the land of opportunity. ", 61 },
        { "A noble steed shall carry thee to victory in battle. ", 53 },
        { "Thou art destined for greatness, but beware the treacherous path ahead. ", 78 },
        { "The stars foretell a bountiful harvest and prosperity for thee and thy kin. ", 73 },
        { "A fair maiden shall capture thy heart, but thou must prove thyself worthy of her love. ", 83 },
        { "Thou shalt embark on a perilous journey, but fear not, for thou shalt return home safely. ", 87 },
        { "Thy wit and cunning shall serve thee well in times of need. ", 56 },
        { "A dark cloud looms over thee, but have faith, for it shall pass and reveal the silver lining. ", 93 },
        { "Thou art blessed with the gift of gab, use it wisely to charm those around thee. ", 66 },
        { "Thy future is shrouded in mystery, embrace the unknown and forge thy own path. ", 80 }
    };

    int choice;
    char input[20];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("\nGreetings, %s! I am here to reveal thy fortune.\n", input);

    printf("Press 1 to receive a random fortune or enter a number between 1 and %d:\n", NUM_FORTUNES - 1);
    scanf("%d", &choice);

    if (choice == 1) {
        int random_index = rand() % NUM_FORTUNES;
        print_fortune(&fortunes[random_index]);
    } else if (choice >= 1 && choice <= NUM_FORTUNES - 1) {
        print_fortune(&fortunes[choice - 1]);
    } else {
        printf("Invalid choice, thou must try again.\n");
    }

    return 0;
}