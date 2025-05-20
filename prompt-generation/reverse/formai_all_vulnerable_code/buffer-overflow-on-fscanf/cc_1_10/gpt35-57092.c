//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_WIDTH 80 // max width of ASCII art
#define MAX_HEIGHT 50 // max height of ASCII art

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'}; // ASCII characters to represent images

int get_gray_value(int r, int g, int b){ // function to get gray value from RGB values
    return (0.299*r + 0.587*g + 0.144*b);
}

int main(){
    char img_name[100]; // character array to store image file name
    printf("Enter image file name: ");
    scanf("%s", img_name);

    char cmd[500]; // command to execute Python code to get image dimensions
    sprintf(cmd, "python -c \"from PIL import Image; img=Image.open('%s'); print(img.size[0], img.size[1]);\"", img_name);
    FILE* fp = popen(cmd, "r"); // execute command and get output
    int width, height;
    fscanf(fp, "%d %d", &width, &height); // parse output
    pclose(fp);

    // calculate scaling factors to fit the image within the ASCII art dimensions
    float w_scale = (float)width / MAX_WIDTH;
    float h_scale = (float)height / MAX_HEIGHT;
    float scale = fmax(w_scale, h_scale);

    // calculate new dimensions of resized image
    int new_width = (int)((float)width / scale);
    int new_height = (int)((float)height / scale);

    // allocate memory for image pixel array
    unsigned char* pixel_array = (unsigned char*)malloc(new_width*new_height*3*sizeof(unsigned char));

    // command to execute Python script to get pixel values of resized image
    sprintf(cmd, "python -c \"from PIL import Image; img=Image.open('%s').resize((%d,%d)); pixels=img.load(); arr=[]; w,h=img.size;\\nfor i in range(h):\\\n\\tfor j in range(w):\\\n\\t\\tr,g,b=pixels[j,i];\\\n\\t\\tarr.append((r,g,b));\\nprint(arr)\"", img_name, new_width, new_height);
    fp = popen(cmd, "r"); // execute command and get output
    for(int i=0; i<new_width*new_height; i++){
        int r, g, b;
        fscanf(fp, "(%d, %d, %d), ", &r, &g, &b); // parse output
        pixel_array[i*3] = r;
        pixel_array[i*3+1] = g;
        pixel_array[i*3+2] = b;
    }
    pclose(fp);

    // allocate memory for ASCII art string
    char* ascii_art = (char*)malloc(MAX_WIDTH*MAX_HEIGHT*sizeof(char));

    // image to ASCII conversion
    for(int i=0; i<new_height; i++){
        for(int j=0; j<new_width; j++){
            int r, g, b;
            r = *(pixel_array + (i*new_width+j)*3);
            g = *(pixel_array + (i*new_width+j)*3 + 1);
            b = *(pixel_array + (i*new_width+j)*3 + 2);
            int gray_value = get_gray_value(r, g, b);
            int char_index = (int)(9.0 * gray_value / 255.0);
            ascii_art[i*MAX_WIDTH+j] = ascii_chars[char_index];
        }
        ascii_art[i*MAX_WIDTH+new_width] = '\n';
    }
    ascii_art[new_height*MAX_WIDTH] = '\0'; // terminating NULL character

    // print the ASCII art
    printf("%s\n", ascii_art);

    // free dynamically allocated memory
    free(pixel_array);
    free(ascii_art);

    return 0;
}