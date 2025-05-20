//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "yourpassword"
#define DATABASE "mind_bending"

void connect_db(MYSQL **conn) {
    *conn = mysql_init(NULL);
    if (*conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(*conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(*conn);
        exit(EXIT_FAILURE);
    }
}

void create_table(MYSQL *conn) {
    const char *create_query = 
    "CREATE TABLE IF NOT EXISTS ideas ("
    "id INT AUTO_INCREMENT PRIMARY KEY,"
    "idea VARCHAR(255) NOT NULL,"
    "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
    ");";
    
    if (mysql_query(conn, create_query)) {
        fprintf(stderr, "Create table failed: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

void insert_idea(MYSQL *conn, const char *idea) {
    char query[512];
    snprintf(query, sizeof(query), "INSERT INTO ideas (idea) VALUES ('%s');", idea);
    
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Insert failed: %s\n", mysql_error(conn));
    }
}

void retrieve_ideas(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM ideas;")) {
        fprintf(stderr, "SELECT failed: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
        return;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void delete_table(MYSQL *conn) {
    const char *delete_query = "DROP TABLE IF EXISTS ideas;";
    
    if (mysql_query(conn, delete_query)) {
        fprintf(stderr, "Drop table failed: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

int main() {
    MYSQL *conn;
    connect_db(&conn);
    create_table(conn);

    int choice;
    char input[255];
    
    do {
        printf("\nMystical Idea Database\n");
        printf("1. Insert Idea\n");
        printf("2. View Ideas\n");
        printf("3. Exit\n");
        printf("Choose your destiny: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter your mind-bending idea: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;  // Remove trailing newline
                insert_idea(conn, input);
                break;
            case 2:
                printf("Retrieving your ideas...\n");
                retrieve_ideas(conn);
                break;
            case 3:
                printf("Farewell, creative mind!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
    
    delete_table(conn);
    mysql_close(conn);
    return 0;
}