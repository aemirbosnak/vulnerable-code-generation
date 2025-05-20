//FormAI DATASET v1.0 Category: Image Steganography ; Style: scientific
#include<stdio.h>

int main(){

    FILE *file_in, *file_out;
    char input_file[100], output_file[100], ch, secret_message[500];
    int i=0, j=0, binary_arr[8];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    printf("Enter the secret message to hide: ");
    scanf("%s", secret_message);

    // convert secret message into binary
    while(secret_message[i] != '\0'){

        for(int k=7; k>=0; k--){
            binary_arr[k] = secret_message[i] % 2;
            secret_message[i] /= 2;
        }
        i++;

        // write binary message into the input file
        file_in = fopen(input_file, "ab");
        fprintf(file_in, "%d", binary_arr[0]);
        fprintf(file_in, "%d", binary_arr[1]);
        fprintf(file_in, "%d", binary_arr[2]);
        fprintf(file_in, "%d", binary_arr[3]);
        fprintf(file_in, "%d", binary_arr[4]);
        fprintf(file_in, "%d", binary_arr[5]);
        fprintf(file_in, "%d", binary_arr[6]);
        fprintf(file_in, "%d", binary_arr[7]);

        fclose(file_in);
    }

    // read image pixel by pixel and hide secret message in binary form inside it
    file_in = fopen(input_file, "rb");
    file_out = fopen(output_file, "wb");

    while(fread(&ch, 1, 1, file_in)){

        if(j<=7){
            binary_arr[j] = ch%2;
            j++;
        }
        else{
            j=0;
            char new_ch = 0;
            for(int k=7; k>=0; k--){
                new_ch = new_ch << 1;
                new_ch = new_ch + binary_arr[k];
            }
            fwrite(&new_ch, 1, 1, file_out);
            fwrite(&ch, 1, 1, file_out);
        }
    }

    // close the files
    fclose(file_in);
    fclose(file_out);

    return 0;
}