//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    char songs[10][50] = {"Melancholy Mist", "Tranquil Symphony", "Frosty Chimes", "Eerie Echo", "Dreamy Bells", "Soothing Sonata", "Dark Lullaby", "Whimsical Waltz", "Enchanted Harp", "Celestial Serenade"};
    char artist[10][50] = {"The Sleepwalkers", "Nightfall Orchestrators", "Mystical Musicians", "Aurora Troubadours", "Crystal Balladeers", "Galactic Harmonizers", "Pixie Poets", "Shadow Syncopators", "Moonglow Melodists", "Stellar String Artists"};
    char genre[4][20] = {"Ambient", "Classical", "New Age", "Experimental"};
    int year[10] = {1989, 1995, 2001, 2007, 2013, 2019, 2025, 2031, 2037, 2043};
    float price[10] = {12.99, 15.50, 18.00, 20.25, 23.49, 27.00, 30.75, 34.99, 39.60, 44.44};
    int quantity[10] = {10, 12, 15, 20, 25, 30, 35, 40, 45, 50};
    int choice = 0, i = 0, j = 0, approval = 0, checkgenre = 0, index = 0, update = 0, genrechoice = 0, yearchoice = 0, quantitychoice = 0;
    
    printf("\n-----Welcome to the Surreal Sounds Music Library Management System!-----\n\n");
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. View music inventory\n");
        printf("2. Update music inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\n-------------MUSIC INVENTORY-------------\n");
                printf("| %-6s | %-25s | %-25s | %-12s | %-6s |\n", "ID", "Song Title", "Artist", "Genre", "Year");
                printf("|--------|---------------------------|---------------------------|-------------|--------|\n");
                for(i=0; i<10; i++){
                    printf("| %-6d | %-25s | %-25s | %-12s | %-6d |\n", i+1, songs[i], artist[i], genre[rand()%4], year[i]);
                }
                printf("----------------------------------------\n");
                break;
                
            case 2:
                printf("\n---------UPDATE MUSIC INVENTORY---------\n");
                printf("| %-6s | %-25s | %-25s | %-8s | %-6s | %-9s |\n", "ID", "Song Title", "Artist", "Genre", "Year", "Quantity");
                printf("|--------|---------------------------|---------------------------|----------|--------|-----------|\n");
                for(i=0; i<10; i++){
                    printf("| %-6d | %-25s | %-25s | %-8s | %-6d | %-9d |\n", i+1, songs[i], artist[i], genre[rand()%4], year[i], quantity[i]);
                }
                printf("----------------------------------------\n");
                printf("\nEnter ID of the song you want to update: ");
                scanf("%d", &index);
                printf("\nDo you want to update the:\n");
                printf("1. Genre\n");
                printf("2. Year\n");
                printf("3. Quantity\n");
                printf("Enter your choice (1/2/3): ");
                scanf("%d", &update);
                
                switch(update){
                    case 1:
                        printf("\n-------UPDATE GENRE-------\n");
                        printf("| %-8s | %-12s |\n", "Choice", "Genre");
                        printf("|----------|-------------|\n");
                        for(i=0; i<4; i++){
                            printf("| %-8d | %-12s |\n", i+1, genre[i]);
                        }
                        printf("---------------------------\n");
                        printf("\nEnter the choice of new genre: ");
                        scanf("%d", &genrechoice);
                        strcpy(genre[index-1], genre[genrechoice-1]);
                        printf("\nThe genre has been updated!\n");
                        break;
                        
                    case 2:
                        printf("\n-------UPDATE YEAR-------\n");
                        printf("Enter the new year: ");
                        scanf("%d", &yearchoice);
                        year[index-1] = yearchoice;
                        printf("\nThe year has been updated!\n");
                        break;
                        
                    case 3:
                        printf("\n-------UPDATE QUANTITY-------\n");
                        printf("Enter the new quantity: ");
                        scanf("%d", &quantitychoice);
                        quantity[index-1] = quantitychoice;
                        printf("\nThe quantity has been updated!\n");
                        break;
                        
                    default:
                        printf("\nInvalid choice!");
                        break;
                }
                break;
                
            case 3:
                printf("\nAre you sure you want to exit? (1/0)");
                scanf("%d", &approval);
                if(approval){
                    printf("\nThank you for using Surreal Sounds Music Library Management System!\n");
                    exit(0);
                }
                break;
                
            default:
                printf("\nInvalid choice!");
                break;
        }
    }
    return 0;
}