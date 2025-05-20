//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int price;
    int growthTime;
    int harvestYield;
} Crop;

typedef struct {
    int balance;
    int cropCount;
    Crop crops[10];
} Farm;

void initializeFarm(Farm *farm) {
    farm->balance = 100;
    farm->cropCount = 0;

    Crop wheat = {"Wheat", 10, 3, 20};
    Crop corn = {"Corn", 15, 5, 30};
    Crop rice = {"Rice", 20, 7, 50};

    farm->crops[0] = wheat;
    farm->crops[1] = corn;
    farm->crops[2] = rice;
}

void displayFarmStatus(Farm *farm) {
    printf("======= Farm Status =======\n");
    printf("Balance: $%d\n", farm->balance);

    if (farm->cropCount == 0) {
        printf("You have no crops planted.\n");
    } else {
        printf("You have %d crops planted:\n", farm->cropCount);
        for (int i = 0; i < farm->cropCount; i++) {
            printf(" - %s\n", farm->crops[i].name);
        }
    }
    printf("===========================\n");
}

void plantCrop(Farm *farm) {
    int choice;
    printf("Choose a crop to plant:\n");
    printf("1. Wheat ($10)\n");
    printf("2. Corn ($15)\n");
    printf("3. Rice ($20)\n");
    printf("0. Cancel\n");
    
    scanf("%d", &choice);
    
    if (choice == 0) {
        return;
    }

    if (choice < 1 || choice > 3) {
        printf("Invalid choice.\n");
        return;
    }
    
    Crop selectedCrop = farm->crops[choice - 1];

    if (farm->balance >= selectedCrop.price) {
        farm->balance -= selectedCrop.price;
        farm->crops[farm->cropCount] = selectedCrop;
        farm->cropCount++;
        printf("You have planted %s!\n", selectedCrop.name);
    } else {
        printf("Insufficient funds to plant %s.\n", selectedCrop.name);
    }
}

void harvestCrops(Farm *farm) {
    if (farm->cropCount == 0) {
        printf("You have no crops to harvest.\n");
        return;
    }

    printf("Harvesting crops...\n");
    for (int i = 0; i < farm->cropCount; i++) {
        int earnings = farm->crops[i].harvestYield;
        farm->balance += earnings;
        printf("You harvested %s and earned $%d!\n", farm->crops[i].name, earnings);
    }
    farm->cropCount = 0; // Clear out all crops after harvesting
}

void showMenu() {
    printf("=========== Menu ===========\n");
    printf("1. Check farm status\n");
    printf("2. Plant a crop\n");
    printf("3. Harvest crops\n");
    printf("4. Quit\n");
    printf("=============================\n");
}

int main() {
    Farm myFarm;
    initializeFarm(&myFarm);
    
    int choice;
    while (1) {
        showMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFarmStatus(&myFarm);
                break;
            case 2:
                plantCrop(&myFarm);
                break;
            case 3:
                harvestCrops(&myFarm);
                break;
            case 4:
                printf("Thank you for playing! Goodbye.\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}