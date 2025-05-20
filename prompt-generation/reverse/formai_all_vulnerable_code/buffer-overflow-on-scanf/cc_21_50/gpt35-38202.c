//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main()
{
    // Character creation
    char name[20], gender;
    printf("Welcome adventurer! What is your name? ");
    scanf("%s", name);
    printf("Greetings, %s! Are you male or female? (M/F) ", name);
    scanf(" %c", &gender);
    
    // Introduction
    printf("\nWelcome, %s, to the land of Eldorath. You are standing at the entrance of a dark dungeon, ready for an adventure. Your goal is to find the magical crystal that was stolen from the village of Helmdor. But beware, the dungeon is filled with dangers and traps. Are you ready to begin your quest?\n\n", name);
    
    // Starting point
    printf("You enter the dungeon and find yourself in a narrow hallway. You can go left or right. Which way do you choose? (L/R) ");
    char direction[10];
    scanf(" %s", direction);
    
    // Left path
    if(strcmp(direction, "L") == 0)
    {
        printf("\nYou find yourself in a room with a big chest in the middle. Do you open it? (Y/N) ");
        char choice[10];
        scanf(" %s", choice);
        
        if(strcmp(choice, "Y") == 0)
        {
            printf("\nThe chest is filled with gold coins! But as you grab one, the floor beneath you opens and you fall into a pit. You see spikes at the bottom. What do you do? (Jump/Wait) ");
            char action[10];
            scanf(" %s", action);
            
            if(strcmp(action, "Jump") == 0)
            {
                printf("\nYou jump and land on a pile of soft hay at the bottom of the pit. You have survived the trap! You see a door at the other end of the room. What do you do? (Go through/Stay) ");
                char nextmove[15];
                scanf(" %s", nextmove);
                
                if(strcmp(nextmove, "Go through") == 0)
                {
                    printf("\nYou open the door and find yourself in a hallway. You can go left or right. Which way do you choose? (L/R) ");
                    char newdir[10];
                    scanf(" %s", newdir);
                    
                    if(strcmp(newdir, "L") == 0)
                    {
                        printf("\nYou find a sword lying on the ground. You pick it up and continue on your journey. You come to a large room with a dragon guarding the exit. What do you do? (Fight/Run) ");
                        char battle[10];
                        scanf(" %s", battle);
                        
                        if(strcmp(battle, "Fight") == 0)
                        {
                            printf("\nYou draw your sword and run towards the dragon. It breathes fire at you, but you dodge it and strike it with your sword. The dragon falls to the ground, defeated. You continue through the exit and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                        }
                        else if(strcmp(battle, "Run") == 0)
                        {
                            printf("\nYou turn around and run back the way you came. You realize you are lost and cannot find your way out. You wander the dungeon for days, hungry and thirsty, until you finally succumb to your injuries and die. Game over.\n");
                        }
                        else
                        {
                            printf("\nInvalid input. Game over. \n");
                        }
                    }
                    else if(strcmp(newdir, "R") == 0)
                    {
                        printf("\nYou entered a room with booby traps. As you went past a trap, a huge boulder fell from above and landed on you. You died. Game over. \n");
                    }
                    else
                    {
                        printf("\nInvalid input. Game over. \n");
                    }
                }
                else if(strcmp(nextmove, "Stay") == 0)
                {
                    printf("\nYou wait for a while, but nothing happens. You decide to go through the door. You open the door and find yourself in a room. ");
                    printf("There are three boxes in front of you. Which one do you choose? (1/2/3) ");
                    int box;
                    scanf(" %d", &box);
                    
                    switch(box)
                    {
                        case 1:
                            printf("\nYou found a key. You can go back and try to open a locked door or continue through the dungeon to find another. What do you do? (Back/Forward) ");
                            char keymove[15];
                            scanf(" %s", keymove);
                            
                            if(strcmp(keymove, "Back") == 0)
                            {
                                printf("\nYou go back to the hallway and try the key on a locked door. The door opens to reveal a room filled with gold and treasure. You win!\n");
                            }
                            else if(strcmp(keymove, "Forward") == 0)
                            {
                                printf("\nYou continue through the dungeon and come to a room with a fierce monster guarding the exit. You cannot defeat it without a weapon. You lose. Game over. \n");
                            }
                            else
                            {
                                printf("\nInvalid input. Game over. \n");
                            }
                            break;
                        
                        case 2:
                            printf("\nYou found a map of the dungeon. You can use it to avoid traps and find shortcuts. You continue through the dungeon and come across a room with a giant spider. What do you do? (Fight/Run) ");
                            char spider[10];
                            scanf(" %s", spider);
                            
                            if(strcmp(spider, "Fight") == 0)
                            {
                                printf("\nYou use your sword to slay the spider. You continue through the dungeon and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                            }
                            else if(strcmp(spider, "Run") == 0)
                            {
                                printf("\nThe spider catches up to you and poisons you. You die a slow and painful death. Game over. \n");
                            }
                            else
                            {
                                printf("\nInvalid input. Game over. \n");
                            }
                            break;
                        
                        case 3:
                            printf("\nYou found a healing potion. You feel reinvigorated and ready for the journey. You continue through the dungeon and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                            break;
                        
                        default:
                            printf("\nInvalid input. Game over. \n");
                            break;
                    }
                }
                else
                {
                    printf("\nInvalid input. Game over. \n");
                }
            }
            else if(strcmp(action, "Wait") == 0)
            {
                printf("\nYou wait, but the spikes come closer and closer. You try to jump back, but it's too late. You fall onto the spikes and die. Game over. \n");
            }
            else
            {
                printf("\nInvalid input. Game over. \n");
            }
        }
        else if(strcmp(choice, "N") == 0)
        {
            printf("\nAs you turn to leave the room, a trap door opens beneath you and you fall into a pit. You see spikes at the bottom. What do you do? (Jump/Wait) ");
            char action[10];
            scanf(" %s", action);
            
            if(strcmp(action, "Jump") == 0)
            {
                printf("\nYou jump and land on a pile of soft hay at the bottom of the pit. You have survived the trap! You see a door at the other end of the room. What do you do? (Go through/Stay) ");
                char nextmove[15];
                scanf(" %s", nextmove);
                
                if(strcmp(nextmove, "Go through") == 0)
                {
                    printf("\nYou open the door and find yourself in a hallway. You can go left or right. Which way do you choose? (L/R) ");
                    char newdir[10];
                    scanf(" %s", newdir);
                    
                    if(strcmp(newdir, "L") == 0)
                    {
                        printf("\nYou find a sword lying on the ground. You pick it up and continue on your journey. You come to a large room with a dragon guarding the exit. What do you do? (Fight/Run) ");
                        char battle[10];
                        scanf(" %s", battle);
                        
                        if(strcmp(battle, "Fight") == 0)
                        {
                            printf("\nYou draw your sword and run towards the dragon. It breathes fire at you, but you dodge it and strike it with your sword. The dragon falls to the ground, defeated. You continue through the exit and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                        }
                        else if(strcmp(battle, "Run") == 0)
                        {
                            printf("\nYou turn around and run back the way you came. You realize you are lost and cannot find your way out. You wander the dungeon for days, hungry and thirsty, until you finally succumb to your injuries and die. Game over.\n");
                        }
                        else
                        {
                            printf("\nInvalid input. Game over. \n");
                        }
                    }
                    else if(strcmp(newdir, "R") == 0)
                    {
                        printf("\nYou entered a room with booby traps. As you went past a trap, a huge boulder fell from above and landed on you. You died. Game over. \n");
                    }
                    else
                    {
                        printf("\nInvalid input. Game over. \n");
                    }
                }
                else if(strcmp(nextmove, "Stay") == 0)
                {
                    printf("\nYou wait for a while, but nothing happens. You decide to go through the door. You open the door and find yourself in a room. ");
                    printf("There are three boxes in front of you. Which one do you choose? (1/2/3) ");
                    int box;
                    scanf(" %d", &box);
                    
                    switch(box)
                    {
                        case 1:
                            printf("\nYou found a key. You can go back and try to open a locked door or continue through the dungeon to find another. What do you do? (Back/Forward) ");
                            char keymove[15];
                            scanf(" %s", keymove);
                            
                            if(strcmp(keymove, "Back") == 0)
                            {
                                printf("\nYou go back to the hallway and try the key on a locked door. The door opens to reveal a room filled with gold and treasure. You win!\n");
                            }
                            else if(strcmp(keymove, "Forward") == 0)
                            {
                                printf("\nYou continue through the dungeon and come to a room with a fierce monster guarding the exit. You cannot defeat it without a weapon. You lose. Game over. \n");
                            }
                            else
                            {
                                printf("\nInvalid input. Game over. \n");
                            }
                            break;
                        
                        case 2:
                            printf("\nYou found a map of the dungeon. You can use it to avoid traps and find shortcuts. You continue through the dungeon and come across a room with a giant spider. What do you do? (Fight/Run) ");
                            char spider[10];
                            scanf(" %s", spider);
                            
                            if(strcmp(spider, "Fight") == 0)
                            {
                                printf("\nYou use your sword to slay the spider. You continue through the dungeon and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                            }
                            else if(strcmp(spider, "Run") == 0)
                            {
                                printf("\nThe spider catches up to you and poisons you. You die a slow and painful death. Game over. \n");
                            }
                            else
                            {
                                printf("\nInvalid input. Game over. \n");
                            }
                            break;
                        
                        case 3:
                            printf("\nYou found a healing potion. You feel reinvigorated and ready for the journey. You continue through the dungeon and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                            break;
                        
                        default:
                            printf("\nInvalid input. Game over. \n");
                            break;
                    }
                }
                else
                {
                    printf("\nInvalid input. Game over. \n");
                }
            }
            else if(strcmp(action, "Wait") == 0)
            {
                printf("\nYou wait, but the spikes come closer and closer. You try to jump back, but it's too late. You fall onto the spikes and die. Game over. \n");
            }
            else
            {
                printf("\nInvalid input. Game over. \n");
            }
        }
        else
        {
            printf("\nInvalid input. Game over. \n");
        }
    }
    
    // Right path
    else if(strcmp(direction, "R") == 0)
    {
        printf("\nYou find yourself in a room with nothing but a door in front of you. You try to open it, but it's locked. You can either try to find a key or force the door open. What do you do? (Find key/Force open) ");
        char door[15];
        scanf(" %s", door);
        
        if(strcmp(door, "Find key") == 0)
        {
            printf("\nYou search the dungeon and come across a room with skeletons on the ground. One of them is holding a key. Do you take it? (Y/N) ");
            char skele[10];
            scanf(" %s", skele);
            
            if(strcmp(skele, "Y") == 0)
            {
                printf("\nYou take the key and return to the locked door. You open it and find yourself in a hallway. You can go left or right. Which way do you choose? (L/R) ");
                char newdir[10];
                scanf(" %s", newdir);
                
                if(strcmp(newdir, "L") == 0)
                {
                    printf("\nYou find a sword lying on the ground. You pick it up and continue on your journey. You come to a large room with a dragon guarding the exit. What do you do? (Fight/Run) ");
                    char battle[10];
                    scanf(" %s", battle);
                    
                    if(strcmp(battle, "Fight") == 0)
                    {
                        printf("\nYou draw your sword and run towards the dragon. It breathes fire at you, but you dodge it and strike it with your sword. The dragon falls to the ground, defeated. You continue through the exit and find the magical crystal in a room just ahead. Congratulations, adventurer, you have completed your quest!\n");
                    }
                    else if(strcmp(battle, "Run") == 0)
                    {
                        printf("\nYou turn around and run back the way you came. You realize you are lost and cannot find your way out. You wander the dungeon for days, hungry and thirsty, until you finally succumb to your injuries and die. Game over.\n");
                    }
                    else
                    {
                        printf("\nInvalid input. Game over. \n");
                    }
                }
                else if(strcmp(newdir, "R") == 0)
                {
                    printf("\nYou entered a room with booby traps. As you went past a trap, a huge boulder fell from above and landed on you. You died. Game over. \n");
                }
                else
                {
                    printf("\nInvalid input. Game over. \n");
                }
            }
            else if(strcmp(skele, "N") == 0)
            {
                printf("\nYou continue through the dungeon and come across a room with a fierce monster guarding the exit. You cannot defeat it without a weapon. You lose. Game over. \n");
            }
            else
            {
                printf("\nInvalid input. Game over. \n");
            }
        }
        else if(strcmp(door, "Force open") == 0)
        {
            printf("\nYou try to force the door open, but it's too strong. You injure yourself in the attempt. ");
            printf("You continue through the dungeon and come across a room with a fierce monster guarding the exit. You cannot defeat it without a weapon. You lose. Game over. \n");
        }
        else
        {
            printf("\nInvalid input. Game over. \n");
        }
    }
    else
    {
        printf("\nInvalid input. Game over. \n");
    }
    
    return 0;
}