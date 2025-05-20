//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_menu() {
    printf("********************************\n");
    printf("*    Welcome to SysAdmin Fun!  *\n");
    printf("********************************\n");
    printf("1. Count down the CPU!\n");
    printf("2. Check memory status\n");
    printf("3. Randomly change directory (and hope it exists)!\n");
    printf("4. Give a motivational quote for your system\n");
    printf("5. Exit the program\n");
    printf("********************************\n");
    printf("Choose your weapon (1-5): ");
}

void countdown_cpu() {
    printf("Initiating CPU countdown! 3... 2... 1...\n");
    for (int i = 3; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("CPU ROCKS! You've just wasted 3 seconds!\n");
}

void check_memory() {
    printf("Let’s check the memory:\n");
    system("free -h");
    printf("Just remember, you have more memory in your head than your computer!\n");
}

void random_directory_change() {
    char *dirs[] = {"/home", "/etc", "/usr", "/var", "/tmp", NULL};
    int random_index = rand() % (sizeof(dirs) / sizeof(dirs[0]) - 1);
    char *selected_dir = dirs[random_index];

    printf("Trying to change to directory: %s\n", selected_dir);
    if (chdir(selected_dir) == 0) {
        printf("Changed directory to %s successfully! 🎉\n", selected_dir);
    } else {
        perror("Failed to change directory! 😱");
    }
}

void motivational_quote() {
    char *quotes[] = {
        "Keep calm and reboot.",
        "There are only two kinds of sysadmins: those who have been hacked and those who will be.",
        "To err is human, to blame it on the computer is even more human.",
        "Why do programmers prefer dark mode? Because light attracts bugs!",
        "Remember: Even the best system will crash... sometimes.",
        NULL
    };
    
    int random_index = rand() % (sizeof(quotes) / sizeof(quotes[0]) - 1);
    printf("Motivational Quote: %s\n", quotes[random_index]);
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                countdown_cpu();
                break;
            case 2:
                check_memory();
                break;
            case 3:
                random_directory_change();
                break;
            case 4:
                motivational_quote();
                break;
            case 5:
                printf("Thanks for playing! Remember to back up your data, just in case! 😜\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again, or go talk to your computer.\n");
        }
        printf("\n");
    }

    return 0;
}