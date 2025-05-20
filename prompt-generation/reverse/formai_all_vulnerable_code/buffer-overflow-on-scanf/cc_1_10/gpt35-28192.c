//FormAI DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>

// Function to recover data from corrupted file
void recoverDataFromFile(char* filename){
    
    // Open the file in read mode
    FILE *fileptr = fopen(filename, "r");
    
    // Create a temporary file to store the recovered data
    FILE *tempfile = tmpfile();
    
    // Check if file is opened successfully
    if (fileptr == NULL) {
        printf("Unable to open file %s.\n", filename);
        return;
    }
    
    // Read data from file
    char buffer[1024];
    int read_count = fread(buffer, 1, sizeof(buffer), fileptr);
    
    // Loop until the end of file is reached
    while(read_count != 0)
    {
        // Check for any error while reading
        if (ferror(fileptr))
        {
            printf("Error while reading data from %s.\n", filename);
            break;
        }
        
        // Write the read data to the temporary file
        fwrite(buffer, 1, read_count, tempfile);

        // Read next chunk of data from the file
        read_count = fread(buffer, 1, sizeof(buffer), fileptr);
        
    }
    
    // Close the file pointer
    fclose(fileptr);
    
    // Close the temporary file pointer
    fclose(tempfile);
    
    // Rename the temporary file to original file
    if(rename(tempfile, filename) != 0)
    {
        printf("Error while renaming the file.");
    }
    else
    {
        printf("File recovered successfully.");
    }
}

// Driver function to test the program
int main()
{
    char filename[100];
    printf("Enter the name of the file to recover data from: ");
    scanf("%s", filename);
    recoverDataFromFile(filename);
    return 0;
}