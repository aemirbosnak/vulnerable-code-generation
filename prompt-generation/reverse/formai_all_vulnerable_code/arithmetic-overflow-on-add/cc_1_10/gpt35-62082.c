//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate unique id
int generateID() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_year+1900;
}

void encrypt(char *text, int key) {
    int i = 0;
    while(text[i] != '\0') {
        text[i] = ((text[i]+key-97)%26)+97;
        i++;
    }
}

void decrypt(char *text, int key) {
    int i = 0;
    while(text[i] != '\0') {
        text[i] = ((text[i]-key-97)%26)+97;
        i++;
    }
}

//structure for the digital diary
struct digital_diary {
    int id;
    char date[15];
    char time[10];
    char message[500];
    char password[20];
    int isEncrypted;
};

int main() {
    //creating a new diary entry
    struct digital_diary entry;
    entry.id = generateID();

    //getting current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(entry.date, sizeof(entry.date), "%d-%m-%Y", tm);
    strftime(entry.time, sizeof(entry.time), "%H:%M:%S", tm);

    //getting the message
    printf("Enter your diary entry:\n");
    fgets(entry.message, sizeof(entry.message), stdin);

    //encryption options
    printf("Do you want to encrypt your message? (yes/no)\n");
    char encrypt_choice[5];
    fgets(encrypt_choice, sizeof(encrypt_choice), stdin);
    if(encrypt_choice[0] == 'y' || encrypt_choice[0] == 'Y') {
        printf("Enter a password for your message encryption:\n");
        fgets(entry.password, sizeof(entry.password), stdin);
        encrypt(entry.message, entry.password[0]);
        entry.isEncrypted = 1;
    }
    else {
        entry.isEncrypted = 0;
    }

    //writing the entry to file
    FILE *fp;
    fp = fopen("digital_diary.txt", "a");
    fprintf(fp, "%d %s %s %s %s %d\n", entry.id, entry.date, entry.time, entry.message, entry.password, entry.isEncrypted);
    fclose(fp);

    //reading the entry from the file
    fp = fopen("digital_diary.txt", "r");
    struct digital_diary read_entry;
    while(fscanf(fp, "%d %s %s %s %s %d", &read_entry.id, read_entry.date, read_entry.time, read_entry.message, read_entry.password, &read_entry.isEncrypted) != EOF) {
        if(read_entry.id == entry.id) {
            if(read_entry.isEncrypted == 1) {
                decrypt(read_entry.message, read_entry.password[0]);
            }
            printf("ID: %d\n", read_entry.id);
            printf("Date: %s\n", read_entry.date);
            printf("Time: %s\n", read_entry.time);
            printf("Message: %s\n", read_entry.message);
            printf("Encryption: %s\n", read_entry.isEncrypted == 1 ? "Yes" : "No");
            break;
        }
    }
    fclose(fp);

    return 0;
}