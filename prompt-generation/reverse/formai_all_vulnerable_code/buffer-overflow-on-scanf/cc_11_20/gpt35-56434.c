//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay (int seconds) {
   int milliseconds = 1000 * seconds;
   clock_t start_time = clock ();
   while (clock () < start_time + milliseconds);
}

int main() {

    printf("You find yourself in a dark, eerie forest. You don't remember how you got here but there's no time to think about that now.\n");
    printf("There are three paths in front of you. Which one do you choose? (Type '1', '2' or '3')\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            printf("You take the first path and enter a clearing. There's a small pond in the middle of it and a giant, talking frog on a lily pad.\n");
            printf("'Hello there, traveler! Are you in search of the potion?' it croaks.\n");
            printf("What do you do?\n");
            printf("1. Ask the frog if it is the potion you're looking for\n");
            printf("2. Ask the frog why it is talking\n");

            int frog_choice;
            scanf("%d", &frog_choice);

            if (frog_choice == 1) {
                printf("'Yes, indeed! I am the potion!' the frog crows. 'But to acquire me, you must defeat my three riddles!'\n");
                printf("Question One: What is the beginning of eternity, the end of time and space?\n");
                char answer1[20];
                int attempts = 0;
                while (attempts < 3) {
                    scanf("%s", answer1);
                    if (strcmp(answer1, "e") == 0 || strcmp(answer1, "E") == 0) {
                        printf("'You have answered my first riddle, traveler, but there will be no mercy in the next two!'\n");
                        break;
                    } else {
                        printf("'Wrong answer! Try again!'\n");
                        attempts++;
                    }
                }

                if (attempts == 3) {
                    printf("You have failed to answer the frog's riddles and are banished from the clearing. Game Over.\n");
                    return 0;
                } else {
                    printf("Question Two: What has a tongue that can't taste, eyes that can't see and a soul that can't be saved?\n");
                    char answer2[20];
                    attempts = 0;
                    while (attempts < 3) {
                        scanf("%s", answer2);
                        if (strcmp(answer2, "shoe") == 0 || strcmp(answer2, "Shoe") == 0) {
                            printf("'You have answered my second riddle, traveler, but you will not be so lucky in the final one!'\n");
                            break;
                        } else {
                            printf("'Wrong answer! Try again!'\n");
                            attempts++;
                        }
                    }

                    if (attempts == 3) {
                        printf("You have failed to answer the frog's riddles and are banished from the clearing. Game Over.\n");
                        return 0;
                    } else {
                        printf("Question Three: What gets wet while drying?\n");
                        char answer3[20];
                        attempts = 0;
                        while (attempts < 3) {
                            scanf("%s", answer3);
                            if (strcmp(answer3, "towel") == 0 || strcmp(answer3, "Towel") == 0) {
                                printf("'Very impressive! You have answered all my riddles, traveler, and have proven yourself worthy of me!'\n");
                                delay(3);
                                printf("You have acquired the potion and are free to go on your way!\n");
                                return 0;
                            } else {
                                printf("'Wrong answer! Try again!'\n");
                                attempts++;
                            }
                        }

                        if (attempts == 3) {
                            printf("You have failed to answer the frog's riddles and are banished from the clearing. Game Over.\n");
                            return 0;
                        }
                    }
                }

            } else if (frog_choice == 2) {
                printf("'Why am I talking?' the frog repeats, confused. 'Why, because I'm a magical frog, of course!'\n");
                printf("You try to ask the frog about the potion again, but it seems to have lost its patience with you. 'You're wasting my time, be gone!' it croaks, and you are banished from the clearing. Game Over.\n");
                return 0;
            }
            break;

        case 2:
            printf("You take the second path and come across an old, abandoned mansion. The door is slightly ajar.\n");
            printf("What do you do? (Type '1' to enter or '2' to continue down the path)\n");

            int mansion_choice;
            scanf("%d", &mansion_choice);

            if (mansion_choice == 1) {
                printf("You enter the mansion and immediately feel a chill run down your spine. The air is thick and musty and the stairs creak under your feet.\n");
                printf("As you ascend to the second floor, you hear a faint sound. It sounds like whispers, or maybe laughter? It's hard to tell.\n");
                printf("You reach the top of the stairs and your heart stops. There is a little girl sitting in the middle of the hallway, playing with a ball.\n");
                printf("'H-hello?' you stutter. 'Are you lost? Do you need help?'\n");
                printf("The girl looks up at you with hollow, black eyes. 'No,' she says in a voice that is not her own. 'But you will.'\n");
                printf("You try to run but find that you can't move. The girl and her ball start to grow larger and larger until they envelop everything.\n");
                printf("You are trapped in an endless cycle of childhood toys and nursery rhymes, doomed to repeat the same day over and over until you go mad. Game Over.\n");
                return 0;
            } else if (mansion_choice == 2) {
                printf("You decide not to enter the mansion, as it gives you an uneasy feeling. You continue down the path.\n");
                break;
            }
            break;

        case 3:
            printf("You take the third path and come across an enchanted garden. The flowers are in full bloom and their petals shimmer like diamonds.\n");
            printf("Suddenly, a beautiful fairy appears before you. 'Welcome, traveler,' she says. 'I am the keeper of this garden. What brings you here?'\n");
            printf("1. Ask the fairy if she knows how to get out of the forest\n");
            printf("2. Admire the beauty of the garden and ask the fairy about it");

            int fairy_choice;
            scanf("%d", &fairy_choice);

            if (fairy_choice == 1) {
                printf("'Ah, I see. You are lost,' the fairy says. 'Fear not, for I can guide you out of this forest. But first, you must help me.'\n");
                printf("'My little fairy friends have been captured by the evil witch who resides in the nearby castle. If you can retrieve them for me, I will help you escape.'\n");
                printf("Do you accept her quest? (Type '1' for Yes or '2' for No)\n");

                int quest_choice;
                scanf("%d", &quest_choice);

                if (quest_choice == 1) {
                    printf("'Thank you, traveler. You are truly wonderful.' The fairy kisses your cheek and disappears, leaving you in the garden.\n");
                    printf("You follow the path and soon come across the witch's castle. The entrance is guarded by a fierce dragon.\n");
                    printf("What do you do? (Type '1' to fight the dragon or '2' to sneak past it)\n");

                    int dragon_choice;
                    scanf("%d", &dragon_choice);

                    if (dragon_choice == 1) {
                        printf("You engage in fierce battle with the dragon and manage to slay it. The entrance to the castle is now clear.\n");
                        printf("You enter the castle and are immediately confronted by the witch. 'So you think you can take my fairy friends from me?' she cackles. 'Think again!'\n");
                        printf("You engage in an intense magical duel with the witch. It lasts for what seems like hours, until you finally emerge victorious.\n");
                        printf("The fairy friends are overjoyed to see you and thank you for your bravery. They lead you out of the forest and on your way back home.\n");
                        printf("Congratulations, you have completed the game!\n");
                        return 0;
                    } else if (dragon_choice == 2) {
                        printf("You sneak past the dragon and enter the castle, but are soon caught by the witch. 'Did you really think you could outsmart me?' she sneers. 'No one can.'\n");
                        printf("You are trapped in a dungeon and left to die. Game Over.\n");
                        return 0;
                    }
                } else if (quest_choice == 2) {
                    printf("'I see,' the fairy says in a disappointed tone. 'Very well, I cannot help you if you will not help me.'\n");
                    printf("You are teleported back to the forest. Game Over.\n");
                    return 0;
                }
            } else if (fairy_choice == 2) {
                printf("'Oh, isn't it just lovely?' the fairy sighs dreamily. 'I have spent many years cultivating this garden. It brings me joy to see others appreciate it.'\n");
                printf("You ask her about the forest and how to escape it.\n");
                printf("'Fear not, traveler. All who wander these woods eventually find their way home.' With that, the fairy disappears in a puff of glitter.\n");
                printf("You continue down the path, wondering what the fairy meant. Eventually you find yourself at the edge of the forest and back in the real world.\n");
                printf("Congratulations, you have completed the game!\n");
                return 0;
            }
            break;

        default:
            printf("Invalid choice. Please try again.");
            return 0;

    }

    // If player reaches this point, they have not won or lost yet
    printf("You continue down the path, unsure of what lies ahead.\n");
    printf("You walk for what seems like hours until you spot a strange, glowing object in the distance. Do you investigate? (Type '1' for Yes or '2' for No)\n");

    int object_choice;
    scanf("%d", &object_choice);

    if (object_choice == 1) {
        printf("You approach the object with caution and find that it is a mysterious cube.\n");
        printf("You decide to investigate further and pick up the cube. Suddenly, you feel a strange energy course through your body.\n");
        printf("You have acquired a new power! You can now control time itself.\n");
        printf("You test out your new power and find that you can pause and resume time at will. You continue down the path, eager to see what other surprises await you.\n");
        printf("The End.");
        return 0;
    } else if (object_choice == 2) {
        printf("You decide not to investigate the object and continue down the path. You soon find yourself at the edge of the forest and back in the real world.\n");
        printf("Congratulations, you have completed the game!\n");
        return 0;
    }

    return 0;
}