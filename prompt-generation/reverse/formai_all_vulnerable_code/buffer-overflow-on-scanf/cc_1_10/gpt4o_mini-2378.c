//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void display_intro() {
    printf("----------------------------------------------------------\n");
    printf("          The Grand Boot Optimizer of the Realm          \n");
    printf("----------------------------------------------------------\n");
    printf("Hail, noble user! Welcome to the Boot Optimization\n");
    printf("Ceremony! It is here that we shall summon the\n");
    printf("power of code to enhance the speed of your noble\n");
    printf("system's startup time. Be wise in your choices!\n");
    printf("----------------------------------------------------------\n\n");
}

void display_options() {
    printf("Select the optimization ritual you wish to perform:\n");
    printf("1. Enchant the Init Process (Optimize Boot Services)\n");
    printf("2. Summon the Gargoyles (Disable Unneeded Services)\n");
    printf("3. Brew a Potion of Cleanliness (Free up Resources)\n");
    printf("4. Exit the Optimization Guild\n");
}

void enchant_init_process() {
    printf("\nPerforming the enchanting of the Init Process...\n");
    // Simulating the optimization process
    sleep(2);
    printf("Alas! The Init Process hath been optimized like never\n");
    printf("before! The boot time hath been reduced by 15 moons!\n");
}

void summon_gargoyles() {
    printf("\nSummoning Gargoyles to remove unneeded services...\n");
    // Simulating the disabling of unnecessary services
    sleep(2);
    printf("The Gargoyles hath swiftly banished the unneeded\n");
    printf("services from thy noble system! Performance hath\n");
    printf("increased as if by magic!\n");
}

void brew_cleanliness_potion() {
    printf("\nBrewing a Potion of Cleanliness...\n");
    // Simulating freeing resources
    sleep(2);
    printf("The resources of thy system are now as clean as the\n");
    printf("purest water from the highest mountains. Wasted resources\n");
    printf("hath been cleansed away!\n");
}

void farewell() {
    printf("\nThank thee for using the Grand Boot Optimizer!\n");
    printf("May thy system run swiftly and without troubles upon\n");
    printf("the next sun's rise. Farewell, noble user!\n");
}

int main() {
    int choice;

    display_intro();

    while (1) {
        display_options();
        printf("Enter thy choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enchant_init_process();
                break;
            case 2:
                summon_gargoyles();
                break;
            case 3:
                brew_cleanliness_potion();
                break;
            case 4:
                farewell();
                exit(0);
            default:
                printf("Alas! That is not a choice within this realm. Try again!\n");
                break;
        }

        printf("\nLet us return to the options for further enhancements!\n");
        sleep(1);
    }

    return 0;
}