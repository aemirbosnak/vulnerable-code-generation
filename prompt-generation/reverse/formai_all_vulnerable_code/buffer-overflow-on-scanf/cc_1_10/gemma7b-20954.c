//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Character creation
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    // Setting the scene
    printf("You find yourself in a quaint, candlelit cafe in the heart of a bustling city.\n");

    // Ordering coffee and pastries
    int choice;
    printf("What would you like to order?\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Hot Chocolate\n");
    printf("4. Pastries\n");
    scanf("%d", &choice);

    // The waiter's response
    switch (choice)
    {
        case 1:
            printf("The waiter smiles and says, 'Certainly, Mr./Ms. %s, a strong brew of coffee with a side of sophistication.\n", name);
            break;
        case 2:
            printf("The waiter nods, 'Certainly, Mr./Ms. %s, a delicate pot of tea, steeped in the finest tradition.\n", name);
            break;
        case 3:
            printf("The waiter beams, 'Ah, Mr./Ms. %s, a delightful cup of hot chocolate, perfect for a romantic evening.\n", name);
            break;
        case 4:
            printf("The waiter winks, 'Certainly, Mr./Ms. %s, a selection of delectable pastries, to satisfy your sweet tooth.\n", name);
            break;
        default:
            printf("The waiter looks confused, 'Excuse me, Mr./Ms. %s, I'm not sure what you're asking for.\n", name);
            break;
    }

    // Ending the scene
    printf("You enjoy your drink and pastry, soaking in the atmosphere of the cafe.\n");

    // Goodbye
    printf("Thank you for visiting, %s. Have a nice day.\n", name);

    return 0;
}