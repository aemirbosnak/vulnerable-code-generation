//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include<stdio.h>
#include<string.h>

struct Album {
    int id;
    char name[50];
    char artist[50];
    char genre[20];
    float price;
    int quantity;
};

struct Album albums[1000];
int numAlbums = 0;

void addAlbum() {
    printf("\nEnter the Album Details:\n");

    albums[numAlbums].id = numAlbums + 1;

    printf("Album Name: ");
    scanf("%s", albums[numAlbums].name);

    printf("Artist: ");
    scanf("%s", albums[numAlbums].artist);

    printf("Genre: ");
    scanf("%s", albums[numAlbums].genre);

    printf("Price: ");
    scanf("%f", &albums[numAlbums].price);

    printf("Quantity: ");
    scanf("%d", &albums[numAlbums].quantity);

    numAlbums++;
}

void displayAlbum(int i) {
    printf("\nAlbum ID: %d\n", albums[i].id);
    printf("Album Name: %s\n", albums[i].name);
    printf("Artist: %s\n", albums[i].artist);
    printf("Genre: %s\n", albums[i].genre);
    printf("Price: %.2f\n", albums[i].price);
    printf("Quantity: %d\n", albums[i].quantity);
}

void displayAllAlbums() {
    if(numAlbums == 0) {
        printf("\nNo Albums in the Library\n");
        return;
    }
    printf("\nAll Albums\n");
    for(int i=0; i<numAlbums; i++) {
        displayAlbum(i);
    }
}

void searchAlbum() {
    char name[50];
    printf("\nEnter the Album Name: ");
    scanf("%s", name);
    for(int i=0; i<numAlbums; i++) {
        if(strcmp(name, albums[i].name) == 0) {
            displayAlbum(i);
            return;
        }
    }
    printf("\nAlbum not found in Library\n");
}

void removeAlbum() {
    int id;
    printf("\nEnter the Album ID to remove: ");
    scanf("%d", &id);

    for(int i=0; i<numAlbums; i++) {
        if(albums[i].id == id) {
            for(int j=i; j<numAlbums-1; j++) {
                albums[j].id = albums[j+1].id - 1;
                strcpy(albums[j].name, albums[j+1].name);
                strcpy(albums[j].artist, albums[j+1].artist);
                strcpy(albums[j].genre, albums[j+1].genre);
                albums[j].price = albums[j+1].price;
                albums[j].quantity = albums[j+1].quantity;
            }
            numAlbums--;
            printf("\nAlbum removed from Library\n");
            return;
        }
    }
    printf("\nAlbum not found in Library\n");
}

int main() {
    int option = 0;
    do {
        printf("\n----C Music Library Management System----\n");
        printf("\n1. Add Album\n2. Display Album\n3. Display All Albums\n4. Search Album\n5. Remove Album\n6. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addAlbum();
                break;
            case 2:
                displayAlbum(0);
                break;
            case 3:
                displayAllAlbums();
                break;
            case 4:
                searchAlbum();
                break;
            case 5:
                removeAlbum();
                break;
            case 6:
                printf("\nThank you for using C Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid option. Try again!\n");
                break;
        }
    } while(option != 6);

    return 0;
}