//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>

int main() {
    printf("Welcome to Invasive Adventure!\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("As you look around, you see a door in front of you and a window to your right.\n");
    
    char choice1;
    printf("Enter 'd' to open the door or 'w' to look out the window: ");
    scanf("%c", &choice1);
    
    if (choice1 == 'd') {
        printf("You open the door and see a long hallway.\n");
        printf("As you start walking down the hallway, you feel like you are being watched.\n");
        
        char choice2;
        printf("Enter 'f' to keep walking or 'r' to turn back: ");
        scanf(" %c", &choice2);
        
        if (choice2 == 'f') {
            printf("You walk until you reach the end of the hallway.\n");
            printf("There is a locked door in front of you.\n");
            
            char choice3;
            printf("Enter 'u' to try to unlock the door or 'b' to go back: ");
            scanf(" %c", &choice3);
            
            if (choice3 == 'u') {
                printf("You try to unlock the door, but the keyhole is too small for your fingers.\n");
                printf("As you turn around, you see a figure approaching you from the other end of the hallway.\n");
                
                char choice4;
                printf("Enter 'r' to run towards the figure or 'h' to hide in a nearby room: ");
                scanf(" %c", &choice4);
                
                if (choice4 == 'r') {
                    printf("You run towards the figure, but it disappears into thin air.\n");
                    printf("Confused and scared, you turn around and see the hallway has changed.\n");
                    printf("Everything seems to be made of flesh and bone, and the walls are pulsating.\n");
                } else if (choice4 == 'h') {
                    printf("You quickly enter a nearby room and lock the door.\n");
                    printf("It's a small room with a single window, but you can't see anything odd outside.\n");
                    printf("You hear footsteps passing by the door, but they soon fade away.\n");
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            } else if (choice3 == 'b') {
                printf("You turn back, but the hallway has changed.\n");
                printf("Everything seems to be made of flesh and bone, and the walls are pulsating.\n");
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else if (choice2 == 'r') {
            printf("You turn back and see the door you came through is gone.\n");
            printf("In a panic, you start running back towards where you woke up.\n");
            printf("But as you run, the walls start to close in on you.\n");
            printf("You struggle to escape, but it's no use.\n");
            printf("The walls engulf you and everything goes black.\n");
            return 0;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } else if (choice1 == 'w') {
        printf("You look out the window, but all you see is darkness.\n");
        printf("Suddenly, you feel a hand grab your shoulder from behind.\n");
        printf("You turn around to see a grotesque creature that resembles a human.\n");
        printf("It has razor-sharp claws, sharp teeth, and a massive hunchback.\n");
        
        char choice5;
        printf("Enter 'a' to fight the creature or 'r' to run: ");
        scanf(" %c", &choice5);
        
        if (choice5 == 'a') {
            printf("You try to fight the creature, but it's too strong and fast.\n");
            printf("It slashes you with its claws, causing massive damage.\n");
            printf("You struggle to stay conscious, but eventually, everything goes black.\n");
            return 0;
        } else if (choice5 == 'r') {
            printf("You run as fast as you can, but the creature is right behind you.\n");
            printf("You make a desperate move and jump out of the window.\n");
            printf("You fall for what feels like forever, but eventually, you land in a body of water.\n");
            printf("You struggle to swim to the surface, but eventually, you make it.\n");
            printf("As you take a few deep breaths, you realize you are in a swamp.\n");
            
            char choice6;
            printf("Enter 'w' to keep swimming or 's' to try to find a way out: ");
            scanf(" %c", &choice6);
            
            if (choice6 == 'w') {
                printf("You keep swimming, but the water is thick and slimy.\n");
                printf("Suddenly, you feel something wrap around your leg and pull you down.\n");
                printf("You struggle to escape, but it's too strong.\n");
                printf("You are dragged under the surface and everything goes black.\n");
                return 0;
            } else if (choice6 == 's') {
                printf("You swim to the closest edge of the swamp and climb out.\n");
                printf("As you look around, you see a dense forest in front of you.\n");
                
                char choice7;
                printf("Enter 'e' to explore the forest or 'c' to stay put: ");
                scanf(" %c", &choice7);
                
                if (choice7 == 'e') {
                    printf("You start walking into the forest, but you soon realize you are lost.\n");
                    printf("The forest seems to be alive, with roots and vines crawling around your feet.\n");
                    printf("You struggle to walk, but eventually, you come across a clearing.\n");
                    
                    char choice8;
                    printf("Enter 'p' to sit down and rest or 'f' to keep walking: ");
                    scanf(" %c", &choice8);
                    
                    if (choice8 == 'p') {
                        printf("You sit down and try to catch your breath.\n");
                        printf("As you relax, you hear a faint singing coming from the trees.\n");
                        printf("It's a beautiful melody, and it seems to be getting closer.\n");
                        printf("You stand up, but before you can do anything else, a massive bird swoops down and grabs you.\n");
                        printf("You struggle to escape, but it's too strong.");
                        printf("Eventually, you give up and everything goes black.\n");
                        return 0;
                    } else if (choice8 == 'f') {
                        printf("You keep walking, but it's getting dark.\n");
                        printf("You try to turn back, but all the trees look the same.\n");
                        printf("Suddenly, you hear a voice calling out to you.\n");
                        printf("'Hey, over here!'");
                        
                        char choice9;
                        printf("Enter 'h' to hide or 'a' to approach the voice: ");
                        scanf(" %c", &choice9);
                        
                        if (choice9 == 'h') {
                            printf("You hide behind a nearby tree, but the voice seems to be getting closer.\n");
                            printf("You peek around the tree and see a figure approaching you.\n");
                            printf("It's a beautiful woman, but she has sharp, fanged teeth and glowing eyes.\n");
                            printf("She smiles and says, 'I've been waiting for you.'\n");
                            printf("You try to run, but she grabs you and brings you in for a kiss.\n");
                            printf("You struggle to get free, but eventually, everything goes black.\n");
                            return 0;
                        } else if (choice9 == 'a') {
                            printf("You walk towards the voice, but as you get closer, you realize it's coming from a massive spider.\n");
                            printf("It's legs are covered in black fur, and its eyes seem to glow in the dark.\n");
                            printf("It creeps closer and closer, and before you can react, it pounces and bites you.\n");
                            printf("You feel a sharp pain and start to feel woozy.\n");
                            printf("The last thing you see is the spider dragging you off into the darkness.\n");
                            return 0;
                        } else {
                            printf("Invalid choice. Try again.\n");
                        }
                    } else {
                        printf("Invalid choice. Try again.\n");
                    }
                } else if (choice7 == 'c') {
                    printf("You stay near the edge of the swamp, hoping someone will find you.\n");
                    printf("You wait for what feels like hours, but no one comes.\n");
                    printf("As the night turns colder, you start to shiver.\n");
                    printf("Soon, you can't move and everything goes black.\n");
                    return 0;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            } else {
                printf("Invalid choice. Try again.\n");
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } else {
        printf("Invalid choice. Try again.\n");
    }
    
    printf("Congratulations, you survived Invasive Adventure!\n");
    return 0;
}