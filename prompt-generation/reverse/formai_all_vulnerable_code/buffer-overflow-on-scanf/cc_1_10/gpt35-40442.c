//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(){
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("example.db", &db);
    
    if (rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    char sql[100];
    printf("Welcome to the Product Database!\n");
    printf("1. Add a new Product\n");
    printf("2. View all Products\n");
    printf("3. Search for a Product\n");
    printf("Enter 1, 2 or 3 to continue: ");
    int option;
    scanf("%d", &option);
    
    switch(option){
        case 1:
            // Add a new Product
            printf("\nEnter the Product name: ");
            char name[100];
            scanf("%s", name);
            printf("Enter the Product price: ");
            double price;
            scanf("%lf", &price);
            sprintf(sql, "INSERT INTO products (product_name, price) VALUES ('%s', '%lf')", name, price);
            
            rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
            if (rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                fprintf(stdout, "New Product added successfully!\n");
            }
            break;
        case 2:
            // View all Products
            sprintf(sql, "SELECT * FROM products");
            rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
            if (rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            }
            break;
        case 3:
            // Search for a Product
            printf("\nEnter the Product name: ");
            char search[100];
            scanf("%s", search);
            sprintf(sql, "SELECT * FROM products WHERE product_name='%s'", search);
            rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
            if (rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            }
            break;
        default:
            printf("Invalid option selected.");
            break;
    }
    
    sqlite3_close(db);
    return 0;
}