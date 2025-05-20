//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encrypt user data before storing in file
char* encrypt(char* input) {
    char key[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char* output = (char*)malloc(strlen(input)+1);
    strcpy(output, input);
    int i, j, index;
    for(i=0; i<strlen(input); i++) {
        index = -1;
        for(j=0; j<strlen(key); j++) {
            if(input[i] == key[j]) {
                index = j;
                break;
            }
        }
        if(index >= 0) {
            output[i] = key[(index+3)%strlen(key)];
        }
    }
    return output;
}

// Function to decrypt user data before displaying on screen
char* decrypt(char* input) {
    char key[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char* output = (char*)malloc(strlen(input)+1);
    strcpy(output, input);
    int i, j, index;
    for(i=0; i<strlen(input); i++) {
        index = -1;
        for(j=0; j<strlen(key); j++) {
            if(input[i] == key[j]) {
                index = j;
                break;
            }
        }
        if(index >= 0) {
            output[i] = key[(index-3+strlen(key))%strlen(key)];
        }
    }
    return output;
}

// Structure to store movie details
struct Movie {
    char title[50];
    float rating;
};

int main() {
    FILE* file;
    file = fopen("movies.txt", "w");

    // Get number of movies to be rated
    int n;
    printf("Enter number of movies to be rated: ");
    scanf("%d", &n);

    // Get movie details and store in file
    struct Movie movie;
    for(int i=0; i<n; i++) {
        printf("Enter title of movie %d: ", i+1);
        scanf("%s", movie.title);
        printf("Enter rating of movie %d (out of 10): ", i+1);
        scanf("%f", &movie.rating);

        // Encrypt movie title before storing in file
        char* encrypted_title = encrypt(movie.title);

        // Store encrypted movie details in file
        fprintf(file, "%s\t%f\n", encrypted_title, movie.rating);
    }
    fclose(file);

    // Read encrypted movie ratings from file and display on screen
    file = fopen("movies.txt", "r");
    printf("\nMovie Ratings\n");
    printf("Title\t\t\tRating\n");
    char line[100];
    char* title;
    while(fgets(line, 100, file)) {
        sscanf(line, "%s\t%f", title, &(movie.rating));
        
        //Decrypt movie title before displaying on screen
        char* decrypted_title = decrypt(title);
        
        // Display decrypted movie details on screen
        printf("%-30s%.1f\n", decrypted_title, movie.rating);
    }

    fclose(file);
    return 0;
}