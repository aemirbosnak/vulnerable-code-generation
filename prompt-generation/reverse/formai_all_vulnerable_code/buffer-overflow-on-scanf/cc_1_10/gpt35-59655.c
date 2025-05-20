//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include<stdio.h>
#include<string.h>

struct song{
    int id;
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

void add_song(struct song arr[], int n){
    printf("Enter song details:\n");
    printf("ID: ");
    scanf("%d", &arr[n].id);
    printf("Title: ");
    scanf("%s", &arr[n].title);
    printf("Artist: ");
    scanf("%s", &arr[n].artist);
    printf("Album: ");
    scanf("%s", &arr[n].album);
    printf("Year: ");
    scanf("%d", &arr[n].year);
    printf("Song added successfully!\n");
}

void display_song(struct song s){
    printf("%d\t%s\t%s\t%s\t%d\n", s.id, s.title, s.artist, s.album, s.year);
}

void display_all_songs(struct song arr[], int n){
    printf("ID\tTitle\tArtist\tAlbum\tYear\n");
    for(int i=0;i<n;i++){
        display_song(arr[i]);
    }
}

void search_song(struct song arr[], int n){
    int search_id;
    printf("Enter song ID to search: ");
    scanf("%d", &search_id);
    for(int i=0;i<n;i++){
        if(arr[i].id==search_id){
            display_song(arr[i]);
            return;
        }
    }
    printf("Song with ID %d not found!\n", search_id);
}

void edit_song(struct song arr[], int n){
    int edit_id;
    printf("Enter song ID to edit: ");
    scanf("%d", &edit_id);
    for(int i=0;i<n;i++){
        if(arr[i].id==edit_id){
            printf("Enter new song details:\n");
            printf("ID: ");
            scanf("%d", &arr[i].id);
            printf("Title: ");
            scanf("%s", &arr[i].title);
            printf("Artist: ");
            scanf("%s", &arr[i].artist);
            printf("Album: ");
            scanf("%s", &arr[i].album);
            printf("Year: ");
            scanf("%d", &arr[i].year);
            printf("Song edited successfully!\n");
            return;
        }
    }
    printf("Song with ID %d not found!\n", edit_id);
}

void delete_song(struct song arr[], int *n){
    int delete_id;
    printf("Enter song ID to delete: ");
    scanf("%d", &delete_id);
    for(int i=0;i<*n;i++){
        if(arr[i].id==delete_id){
            for(int j=i;j<*n-1;j++){
                arr[j]=arr[j+1];
            }
            (*n)--;
            printf("Song deleted successfully!\n");
            return;
        }
    }
    printf("Song with ID %d not found!\n", delete_id);
}

int main(){
    struct song library[100];
    int n=0, choice=0;
    while(choice!=6){
        printf("\n********** Music Library Management System **********\n");
        printf("\n1. Add Song\n2. Display All Songs\n3. Search Song\n4. Edit Song\n5. Delete Song\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_song(library, n);
                    n++;
                    break;
            case 2: if(n==0){
                        printf("No songs in the library!\n");
                    }
                    else{
                        display_all_songs(library, n);
                    }
                    break;
            case 3: if(n==0){
                        printf("No songs in the library!\n");
                    }
                    else{
                        search_song(library, n);
                    }
                    break;
            case 4: if(n==0){
                        printf("No songs in the library!\n");
                    }
                    else{
                        edit_song(library, n);
                    }
                    break;
            case 5: if(n==0){
                        printf("No songs in the library!\n");
                    }
                    else{
                        delete_song(library, &n);
                    }
                    break;
            case 6: printf("Goodbye!\n");
                    break;
            default: printf("Invalid choice!\n");
                     break;
        }
    }
    return 0;
}