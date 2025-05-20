//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller(void);

int main(void) {
    srand(time(NULL));
    int choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fortune_teller();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 2);

    return 0;
}

void fortune_teller(void) {
    int random_number;
    char *fortunes[] = {"You will have a lucky day today. ",
                        "A great opportunity will come your way. ",
                        "Someone close to you will surprise you. ",
                        "You will achieve success in your endeavors. ",
                        "A pleasant surprise awaits you. ",
                        "You will receive good news soon. ",
                        "Your hard work will pay off. ",
                        "A new adventure is on the horizon. ",
                        "Your dreams will come true. ",
                        "You will find love and happiness. ",
                        "A financial windfall is headed your way. ",
                        "Your health will improve. ",
                        "Your creativity will be unleashed. ",
                        "You will make a new friend. ",
                        "Your problems will be resolved. ",
                        "You will have a peaceful day. ",
                        "You will be surrounded by positivity. ",
                        "You will be blessed with good fortune. ",
                        "You will have a successful career. ",
                        "You will travel to exciting places. ",
                        "You will be filled with joy and happiness."};

    random_number = rand() % 20;

    printf("Your fortune is:\n%s\n", fortunes[random_number]);
}