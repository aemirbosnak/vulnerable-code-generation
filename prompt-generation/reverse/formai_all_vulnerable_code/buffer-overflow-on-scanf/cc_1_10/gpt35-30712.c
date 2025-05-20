//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to perform digital watermarking
void watermark(char *image_path, char* watermark_text, char* final_image_path){
    FILE* fptr1 = fopen(image_path, "rb");
    FILE* fptr2 = fopen(watermark_text, "r");
    FILE* fptr3 = fopen(final_image_path, "wb");

    char image_data[100], watermark_data[100];
    int image_idx=0, watermark_idx=0;
    int i=0, j=0;

    while(!feof(fptr2)){
        watermark_data[watermark_idx++] = fgetc(fptr2);
    }
    watermark_data[watermark_idx] = '\0';

    while(fread(image_data, sizeof(image_data), 1, fptr1) == 1){
        for(i=0; i<strlen(watermark_data); i++){
            for(j=0; j<sizeof(image_data); j++){
                if(image_data[j] == watermark_data[i]){
                    image_data[j] = ~image_data[j];
                }
            }
        }
        fwrite(image_data, sizeof(image_data), 1, fptr3);
        image_idx++;
    } 
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);

    printf("Watermarking complete!\n");
}

// Main function for multiplayer style
int main(){
    int num_players, i;
    char image_path[50], final_image_path[50];

    printf("Welcome to Digital Watermarking multiplayer game!\n");
    printf("How many players are there (minimum 2)? ");
    scanf("%d", &num_players);

    // Loop through each player
    for(i=1; i<=num_players; i++){
        printf("Player %d, enter path to image: ", i);
        scanf("%s", image_path);
        printf("Player %d, enter path to watermark text: ", i);
        char watermark_path[50];
        scanf("%s", watermark_path);

        // Watermark the image for current player
        char final_path[50];
        sprintf(final_path, "player_%d_marked.bmp", i);
        watermark(image_path, watermark_path, final_path);
    }

    printf("All players have completed watermarking their images!\n");

    // Merge all the watermarked images
    FILE* merged_file = fopen("final_image.bmp", "w");

    for(i=1; i<=num_players; i++){
        char player_file[50];
        sprintf(player_file, "player_%d_marked.bmp", i);

        char player_data[100];
        FILE* current_file = fopen(player_file, "r");
        while(fread(player_data, sizeof(player_data), 1, current_file) == 1){
            fwrite(player_data, sizeof(player_data), 1, merged_file);
        }
        fclose(current_file);
    }
    fclose(merged_file);

    printf("All images have been merged into one final image!");
    return 0;
}